#include "EventBusThreadSafeImpl.h"
#include "BroadcastReceiver.h"
#include "StringUtil.h"
#include <stdint.h>
#ifdef __APPLE__
#include <dlfcn.h>
#include <sys/types.h>
#include <unistd.h>
#else
#include <Windows.h>
#include <io.h>
#include <process.h>
#endif

IEventBus *IEventBus::Instance() {
  return EventBusThreadSafeImpl::GetInstance();
}

bool EventBusDataModel::IsModuleDescExist(const std::string &moduleId) const {
  std::lock_guard<std::mutex> guard(m_dataAccessMutex);
  return m_mapModuleDesc.find(moduleId) != m_mapModuleDesc.end();
}

ModuleDesc EventBusDataModel::GetModuleDesc(const std::string &moduleId) const {
  std::lock_guard<std::mutex> guard(m_dataAccessMutex);
  std::map<std::string, ModuleDesc>::const_iterator itFind =
      m_mapModuleDesc.find(moduleId);
  if (itFind == m_mapModuleDesc.end()) {
    return {};
  }

  return itFind->second;
}

bool EventBusDataModel::AddModuleDesc(const std::string &moduleId,
                                      const ModuleDesc &desc) {
  std::lock_guard<std::mutex> guard(m_dataAccessMutex);
  m_mapModuleDesc[moduleId] = desc;
  return true;
}

ModuleDesc EventBusDataModel::RemoveModuleDesc(const std::string &moduleId) {
  std::lock_guard<std::mutex> guard(m_dataAccessMutex);
  ModuleDesc desc{};
  auto find = m_mapModuleDesc.find(moduleId);
  if (find == m_mapModuleDesc.end()) {
    return desc;
  }

  desc = find->second;
  m_mapModuleDesc.erase(find);
  return desc;
}

std::vector<std::string> EventBusDataModel::GetModules() {
  std::vector<std::string> modules;
  for (auto &module : m_mapModuleDesc) {
    modules.push_back(module.first);
  }
  return modules;
}

EventBusThreadSafeImpl::EventBusThreadSafeImpl() {}

EventBusThreadSafeImpl::~EventBusThreadSafeImpl() {}

bool EventBusThreadSafeImpl::Init(SDKEventLoopContext contextEventLoop) {
#ifndef __APPLE__
  HRESULT hr = ::CoInitialize(NULL);
  // remove current dir on dll search path
  ::SetDllDirectoryA("");
#endif

  BroadcastReceiver::GetInstance()->Init(
      [this](const std::string &moduleIdTo, uint64_t notifyId, void *notify) {
        auto desc = m_dataModel.GetModuleDesc(moduleIdTo);
        if (!desc.isValid()) {
          return;
        }

        return desc.pfnOnNotify(notifyId, notify);
      });

  m_contextEventLoop = contextEventLoop;
  return true;
}

bool EventBusThreadSafeImpl::InitModule(const std::string &moduleId,
                                        const std::string &moduleFile) {
  if (moduleId.empty()) {
    return false;
  }

  if (m_dataModel.IsModuleDescExist(moduleId)) {
    return true;
  }

  ModuleDesc desc{};
  if (!initModule(moduleId, moduleFile, desc)) {
    // revert insert before this then continue?
    return false;
  }
  return true;
}

bool EventBusThreadSafeImpl::UninitModule(const std::string &moduleId) {
  if (moduleId.empty()) {
    return false;
  }

  auto desc = m_dataModel.RemoveModuleDesc(moduleId);
  if (!desc.isValid()) {
    return false;
  }

  if (desc.pfnUninit != nullptr) {
    desc.pfnUninit();
  }
  uninitModule(desc.handle);

  return true;
}

void *EventBusThreadSafeImpl::CallModuleEvent(const std::string &moduleIdTo,
                                              uint64_t eventId, void *event) {
  auto desc = m_dataModel.GetModuleDesc(moduleIdTo);
  if (!desc.isValid()) {
    return nullptr;
  }

  return desc.pfnCallEvent(eventId, event);
}

void EventBusThreadSafeImpl::CallModuleDrop(const std::string &moduleIdTo,
                                            uint64_t eventId, void *drop) {
  auto desc = m_dataModel.GetModuleDesc(moduleIdTo);
  if (!desc.isValid()) {
    return;
  }

  return desc.pfnCallDrop(eventId, drop);
}

void *CallModuleEvent(const char *moduleIdTo, uint64_t eventId, void *event) {
  return IEventBus::Instance()->CallModuleEvent(moduleIdTo, eventId, event);
}

void CallModuleDrop(const char *moduleIdTo, uint64_t eventId, void *drop) {
  return IEventBus::Instance()->CallModuleDrop(moduleIdTo, eventId, drop);
}

void OnModuleNotify(const char *moduleIdFrom, uint64_t notifyId, void *notify) {
  BroadcastReceiver::GetInstance()->OnModuleNotify(moduleIdFrom, notifyId,
                                                   notify);
}

bool EventBusThreadSafeImpl::Uninit() {
  const auto modules = m_dataModel.GetModules();
  for (const auto &module : modules) {
    UninitModule(module);
  }

  BroadcastReceiver::GetInstance()->Uninit();
#ifdef __APPLE__
#else
  ::CoUninitialize();
#endif
  return true;
}

bool EventBusThreadSafeImpl::RegisterObserver(const char *moduleId,
                                              PFNOnModuleNotify observer) {
  if (nullptr == moduleId || nullptr == observer) {
    return false;
  }
  return BroadcastReceiver::GetInstance()->RegisterObserver(moduleId, observer);
}

bool EventBusThreadSafeImpl::RevokeObserver(const char *moduleId,
                                            PFNOnModuleNotify observer) {
  if (nullptr == moduleId || nullptr == observer) {
    return false;
  }
  return BroadcastReceiver::GetInstance()->RevokeObserver(moduleId, observer);
}

bool EventBusThreadSafeImpl::RegisterObserverModule(
    const char *moduleId, const char *moduleIdObserver) {
  if (nullptr == moduleId || nullptr == moduleIdObserver) {
    return false;
  }
  return BroadcastReceiver::GetInstance()->RegisterObserver(moduleId,
                                                            moduleIdObserver);
}

bool EventBusThreadSafeImpl::RevokeObserverModule(
    const char *moduleId, const char *moduleIdObserver) {
  if (nullptr == moduleId || nullptr == moduleIdObserver) {
    return false;
  }
  return BroadcastReceiver::GetInstance()->RevokeObserver(moduleId,
                                                          moduleIdObserver);
}

bool EventBusThreadSafeImpl::initModule(const std::string &moduleId,
                                        const std::string &fileName,
                                        ModuleDesc &desc) {
  unsigned int error = 0;
  {
#ifdef __APPLE__
    dlerror();
    desc.handle = dlopen(fileName.c_str(), RTLD_LAZY);
#else
    desc.handle = ::LoadLibraryExW(
        SDK_COMMON::StringUtil::Utf8ToUnicode(fileName).c_str(), NULL,
        LOAD_WITH_ALTERED_SEARCH_PATH);
    error = ::GetLastError();
#endif
  }
  if (nullptr == desc.handle) {
#ifdef __APPLE__
#pragma unused(error)
    const char *errMsg = dlerror();
#else
#endif
    return false;
  }
#ifdef __APPLE__
  desc.pfnInit = (PFNInit)dlsym(desc.handle, "ExportedInit");
  desc.pfnCallEvent = (PFNCallEvent)dlsym(desc.handle, "ExportedCallEvent");
  desc.pfnCallDrop = (PFNCallDrop)dlsym(desc.handle, "ExportedCallDrop");
  desc.pfnOnNotify = (PFNOnNotify)dlsym(desc.handle, "ExportedNotify");
  desc.pfnUninit = (PFNUninit)dlsym(desc.handle, "ExportedUninit");
#else
  desc.pfnInit = (PFNInit)GetProcAddress(desc.handle, "ExportedInit");
  desc.pfnCallEvent =
      (PFNCallEvent)GetProcAddress(desc.handle, "ExportedCallEvent");
  desc.pfnCallDrop =
      (PFNCallDrop)GetProcAddress(desc.handle, "ExportedCallDrop");
  desc.pfnOnNotify =
      (PFNOnNotify)GetProcAddress(desc.handle, "ExportedOnNotify");
  desc.pfnUninit = (PFNUninit)GetProcAddress(desc.handle, "ExportedUninit");
#endif
  if (!desc.isValid()) {
    return false;
  }
  m_dataModel.AddModuleDesc(moduleId, desc);
  // 模块通过函数指针来调用其他模块的函数，而不是通过EventBus_CallModuleEvent，是为了去除其他模块对eventbus模块的编译依赖

  desc.pfnInit(::CallModuleEvent, ::CallModuleDrop, ::OnModuleNotify,
               &m_contextEventLoop);
  return true;
}

bool EventBusThreadSafeImpl::uninitModule(module_handle_t handle) {
  if (handle) {
#ifdef __APPLE__
    dlclose(handle);
#else
    if (!::FreeLibrary(handle)) {
    }
#endif
    handle = nullptr;
  }

  return true;
}

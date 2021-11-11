#pragma once

#include "IEventBus.h"

class EventBusDataModel {
public:
  bool IsModuleDescExist(const std::string &moduleId) const;
  ModuleDesc GetModuleDesc(const std::string &moduleId) const;
  bool AddModuleDesc(const std::string &moduleId, const ModuleDesc &desc);
  ModuleDesc RemoveModuleDesc(const std::string &moduleId);
  std::vector<std::string> GetModules();

private:
  std::map<std::string, ModuleDesc> m_mapModuleDesc;
  mutable std::mutex m_dataAccessMutex;
};

class EventBusThreadSafeImpl
    : public IEventBus,
      public SDK_COMMON::Singleton<EventBusThreadSafeImpl> {
  EventBusThreadSafeImpl(const EventBusThreadSafeImpl &) = delete;
  EventBusThreadSafeImpl &operator=(const EventBusThreadSafeImpl &) = delete;

private:
  typedef std::function<bool(uint64_t requestId, void *)> RequestHandler;

private:
  EventBusDataModel m_dataModel;
  std::map<std::string, std::vector<std::string>> m_mapPackage;
  std::map<std::string, ModuleDesc> m_mapModuleDesc;

private:
  SDKEventLoopContext m_contextEventLoop;

public:
  EventBusThreadSafeImpl();
  ~EventBusThreadSafeImpl();

public:
  bool Init(SDKEventLoopContext contextEventLoop); // and the deps of module
  bool Uninit();

  bool RegisterObserver(const char *moduleId, PFNOnModuleNotify observer);
  bool RevokeObserver(const char *moduleId, PFNOnModuleNotify observer);

  bool RegisterObserverModule(const char *moduleId,
                              const char *moduleIdObserver);
  bool RevokeObserverModule(const char *moduleId, const char *moduleIdObserver);

  bool InitModule(const std::string &moduleId, const std::string &moduleFile);
  bool UninitModule(const std::string &moduleId);

  void *CallModuleEvent(const std::string &moduleIdTo, uint64_t eventId,
                        void *event);
  void CallModuleDrop(const std::string &moduleIdTo, uint64_t eventId,
                      void *drop);

private:
  bool initModule(const std::string &moduleId, const std::string &fileName,
                  ModuleDesc &desc);
  bool uninitModule(module_handle_t handle);
};

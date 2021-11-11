#include <string>
#include <vector>

#include "EventBus.h"
#include "IEventBus.h"

bool EventBus_Init(SDKEventLoopContext contextEventLoop) {
  IEventBus::Instance()->Init(contextEventLoop);
  return true;
}

bool EventBus_InitModule(const char *moduleId, const char *moduleFile) {
  if (nullptr == moduleId || nullptr == moduleFile) {
    return false;
  }

  return IEventBus::Instance()->InitModule(moduleId, moduleFile);
}

bool EventBus_UninitModule(const char *moduleId) {
  if (nullptr == moduleId) {
    return false;
  }
  return IEventBus::Instance()->UninitModule(moduleId);
}

void *EventBus_CallEvent(const char *moduleIdTo, uint64_t eventId,
                         void *event) {
  if (nullptr == moduleIdTo) {
    return nullptr;
  }
  return IEventBus::Instance()->CallModuleEvent(moduleIdTo, eventId, event);
}

void EventBus_CallDrop(const char *moduleIdTo, uint64_t dropId, void *drop) {
  if (nullptr == moduleIdTo) {
    return;
  }
  return IEventBus::Instance()->CallModuleDrop(moduleIdTo, dropId, drop);
}

bool EventBus_RegisterObserver(const char *moduleId,
                               PFNOnModuleNotify observer) {
  return IEventBus::Instance()->RegisterObserver(moduleId, observer);
}

bool EventBus_RevokeObserver(const char *moduleId, PFNOnModuleNotify observer) {
  return IEventBus::Instance()->RevokeObserver(moduleId, observer);
}

bool EventBus_RegisterObserverModule(const char *moduleId,
                                     const char *moduleIdObserver) {
  return IEventBus::Instance()->RegisterObserverModule(moduleId,
                                                       moduleIdObserver);
}

bool EventBus_RevokeObserverModule(const char *moduleId,
                                   const char *moduleIdObserver) {
  return IEventBus::Instance()->RevokeObserverModule(moduleId,
                                                     moduleIdObserver);
}

bool EventBus_Uninit() {
  bool ret = IEventBus::Instance()->Uninit();
  return ret;
}

#pragma once

#include <functional>
#include <map>
#include <memory>
#include <mutex>
#include <set>
#include <stdint.h>
#include <string>
#include <vector>

#ifndef __APPLE__
#include <Windows.h>
#endif
#include "EventBus.h"
#include "Singleton.h"

typedef bool (*PFNInit)(PFNCallModuleEvent callModuleEvent,
                        PFNCallModuleDrop callModuleDrop,
                        PFNOnModuleNotify onModuleNotify,
                        SDKEventLoopContext *eventLoopContext);
typedef void *(*PFNCallEvent)(uint64_t eventId, void *event);
typedef void (*PFNCallDrop)(uint64_t eventId, void *event);
typedef void (*PFNOnNotify)(uint64_t notifyId, void *notify);
typedef bool (*PFNUninit)();

#ifdef __APPLE__
using module_handle_t = void *;
#else
using module_handle_t = HMODULE;
#endif
struct ModuleDesc {
  module_handle_t handle = nullptr;
  PFNInit pfnInit = nullptr;
  PFNCallEvent pfnCallEvent = nullptr;
  PFNCallDrop pfnCallDrop = nullptr;
  PFNOnNotify pfnOnNotify = nullptr;
  PFNUninit pfnUninit = nullptr;

  bool isValid() const {
    if (nullptr == handle || nullptr == pfnInit || nullptr == pfnCallEvent ||
        nullptr == pfnOnNotify || nullptr == pfnUninit) {
      return false;
    }

    return true;
  }
};

class IEventBus {
public:
  IEventBus() = default;
  virtual ~IEventBus() = default;

  static IEventBus *Instance();

public:
  virtual bool
  Init(SDKEventLoopContext contextEventLoop) = 0; // and the deps of module
  virtual bool Uninit() = 0;

  virtual bool RegisterObserver(const char *moduleId,
                                PFNOnModuleNotify observer) = 0;
  virtual bool RevokeObserver(const char *moduleId,
                              PFNOnModuleNotify observer) = 0;

  virtual bool RegisterObserverModule(const char *moduleId,
                                      const char *moduleIdObserver) = 0;
  virtual bool RevokeObserverModule(const char *moduleId,
                                    const char *moduleIdObserver) = 0;

  virtual bool InitModule(const std::string &moduleId,
                          const std::string &moduleFile) = 0;
  virtual bool UninitModule(const std::string &moduleId) = 0;

  virtual void *CallModuleEvent(const std::string &moduleIdTo, uint64_t eventId,
                                void *event) = 0;
  virtual void CallModuleDrop(const std::string &moduleIdTo, uint64_t dropId,
                              void *drop) = 0;
};

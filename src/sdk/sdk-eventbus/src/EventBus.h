#pragma once

#include "DylibDef.h"
#include <stddef.h>
#include <stdint.h>

extern "C" {
#pragma pack(push, 1)

// event bus提供给其他模块的能力（最终由应用层实现）
struct SDKEventLoopContext {
  uint64_t (*pfnAddTimer)(uint64_t interval, void (*pfnTimer)(void *), void *);
  void (*pfnRemoveTimer)(uint64_t timerId);
  uint64_t (*pfnAddDelayTask)(uint64_t delay, void (*pfnTask)(void *), void *);
  void (*pfnRemoveDelayTask)(uint64_t taskId);
  void (*pfnRunOnMainThreadSync)(void (*pfnRun)(void *), void *);
  uint64_t (*pfnRunOnMainThreadAsyn)(void (*pfnRun)(void *), void *);
};

#pragma pack(pop)

// 模块对其他模块发出call event请求
typedef void *(*PFNCallModuleEvent)(const char *moduleIdTo, uint64_t eventId,
                                    void *event);
// 模块对其他模块发出call drop请求
typedef void (*PFNCallModuleDrop)(const char *moduleIdTo, uint64_t eventId,
                                  void *drop);
// 模块发出的通知事件
typedef void (*PFNOnModuleNotify)(const char *moduleIdFrom, uint64_t notifyId,
                                  void *notify);

SDK_API bool EventBus_Init(SDKEventLoopContext contextEventLoop);
SDK_API bool EventBus_Uninit();

// 注册指定模块的通知事件，通过指定observer函数处理
// 一般应用层关心某些模块的事件使用此函数注册观察者
SDK_API bool EventBus_RegisterObserver(const char *moduleId,
                                       PFNOnModuleNotify observer);
SDK_API bool EventBus_RevokeObserver(const char *moduleId,
                                     PFNOnModuleNotify observer);

// 注册指定模块的通知事件，通过指定moduleIdObserver模块的EventBus_OnNotify函数处理
// 一般某些模块关心其他模块的事件使用此函数注册观察者
SDK_API bool EventBus_RegisterObserverModule(const char *moduleId,
                                             const char *moduleIdObserver);
SDK_API bool EventBus_RevokeObserverModule(const char *moduleId,
                                           const char *moduleIdObserver);

// 初始化模块，内部加载模块动态库
// 应用层根据模块依赖关系管理模块加载，卸载
SDK_API bool EventBus_InitModule(const char *moduleId, const char *moduleFile);
SDK_API bool EventBus_UninitModule(const char *moduleId);

// 调用模块接口（应用层使用）
SDK_API bool EventBus_CallModuleEvent(const char *moduleIdTo, uint64_t eventId,
                                      void *event);
// 清理返回值
SDK_API bool EventBus_CallModuleDrop(const char *moduleIdTo, uint64_t dropId,
                                     void *drop);
}

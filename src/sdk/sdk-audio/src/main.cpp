#include <iostream>
#include <string>
#include <vector>

#include "DylibDef.h"

// idl声明
// event
std::vector<std::string> GetAudioDevice();
void adjustVolume(std::string device);

// notify
void VolumeChangeNotify(std::string device, int volume);

// event bus相关代码都可以根据idl自动化生成
/***************event bus****************/

// event bus ID定义
#define GetAudioDeviceEventID 1
#define VolumeChangeNotifyID 1

#define MODULEID "sdk-audio"

// event bus接口
typedef void *(*PFNCallModuleEvent)(const char *moduleIdTo, uint64_t eventId,
                                    void *event);
typedef void (*PFNCallModuleDrop)(const char *moduleIdTo, uint64_t eventId,
                                  void *drop);
typedef void (*PFNOnModuleNotify)(const char *moduleIdFrom, uint64_t notifyId,
                                  void *notify);

extern "C" {
#pragma pack(push, 1)

struct SDKEventLoopContext {
  uint64_t (*pfnAddTimer)(uint64_t interval, void (*pfnTimer)(void *), void *);
  void (*pfnRemoveTimer)(uint64_t timerId);
  uint64_t (*pfnAddDelayTask)(uint64_t delay, void (*pfnTask)(void *), void *);
  void (*pfnRemoveDelayTask)(uint64_t taskId);
  void (*pfnRunOnMainThreadSync)(void (*pfnRun)(void *), void *);
  uint64_t (*pfnRunOnMainThreadAsyn)(void (*pfnRun)(void *), void *);
};

#pragma pack(pop)
}

PFNCallModuleEvent g_callModuleEvent = nullptr;
PFNCallModuleDrop g_callModuleDrop = nullptr;
PFNOnModuleNotify g_onModuleNotify = nullptr;

SDK_API bool ExportedInit(PFNCallModuleEvent callModuleEvent,
                          PFNCallModuleDrop callModuleDrop,
                          PFNOnModuleNotify onModuleNotify,
                          SDKEventLoopContext *eventLoopContext) {
  std::cout << "sdk-audio  ExportedInit" << std::endl;
  g_callModuleEvent = callModuleEvent;
  g_callModuleDrop = callModuleDrop;
  g_onModuleNotify = onModuleNotify;
  return true;
}

SDK_API void *ExportedCallEvent(uint64_t eventId, void *event) {
  std::cout << "sdk-audio ExportedCallEvent " << eventId << std::endl;
  if (eventId == GetAudioDeviceEventID) {
    auto ret1 = new std::vector<std::string>();
    auto ret2 = GetAudioDevice();
    *ret1 = ret2;
    return (void *)ret1;
  }

  return nullptr;
}

SDK_API void ExportedCallDrop(uint64_t eventId, void *drop) {
  std::cout << "sdk-audio ExportedCallDrop " << eventId << std::endl;
  if (eventId == GetAudioDeviceEventID) {
    auto ret1 = (std::vector<std::string> *)drop;
    delete ret1;
  }
}

SDK_API void ExportedNotify(uint64_t notifyId, void *notify) {
  std::cout << "sdk-audio ExportedNotify " << notifyId << std::endl;
}

SDK_API bool ExportedUninit() {
  std::cout << "sdk-audio ExportedUninit " << std::endl;
  return true;
}

// idl实现
std::vector<std::string> GetAudioDevice() {
  std::cout << "sdk-audio GetAudioDevice" << std::endl;
  std::vector<std::string> devices;
  devices.push_back("audioDevice1");
  devices.push_back("audioDevice2");
  return devices;
}

void adjustVolume(std::string device) {
  std::cout << "sdk-audio adjustVolume " << device << std::endl;
  VolumeChangeNotify(device, 1);
  VolumeChangeNotify(device, 2);
  VolumeChangeNotify(device, 3);
}

void VolumeChangeNotify(std::string device, int volume) {
  g_onModuleNotify(MODULEID, VolumeChangeNotifyID, (void *)volume);
}
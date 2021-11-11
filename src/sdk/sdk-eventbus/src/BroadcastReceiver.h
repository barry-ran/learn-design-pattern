#pragma once

#include <functional>
#include <list>
#include <map>
#include <string>

#include "EventBus.h"
#include "Singleton.h"

class BroadcastReceiver : public SDK_COMMON::Singleton<BroadcastReceiver> {
  BroadcastReceiver(const BroadcastReceiver &) = delete;
  BroadcastReceiver &operator=(const BroadcastReceiver &) = delete;

private:
  typedef std::function<bool(uint64_t notifyId, void *)> NotifyHandler;

private:
  std::map<std::string, std::list<PFNOnModuleNotify>> m_mapNotifyFunction;
  std::map<std::string, std::list<std::string>> m_mapNotifyModule;
  std::function<void(const std::string &, uint64_t notifyId, void *)>
      m_pfnOnModuleReceiver = nullptr;

public:
  BroadcastReceiver() = default;
  ~BroadcastReceiver() = default;

public:
  bool Init(const std::function<void(const std::string &, uint64_t notifyId,
                                     void *)> &onModuleReceiver);
  bool Uninit();

public:
  bool RegisterObserver(const std::string &moduleId,
                        PFNOnModuleNotify observer);
  bool RevokeObserver(const char *moduleId, PFNOnModuleNotify observer);

  bool RegisterObserver(const std::string &moduleId,
                        const std::string &moduleIdObserver);
  bool RevokeObserver(const char *moduleId,
                      const std::string &moduleIdObserver);

public:
  void OnModuleNotify(const std::string &moduleIdFrom, uint64_t notifyId,
                      void *notify);

private:
  void onNotifyFunction(const std::string &moduleIdFrom, uint64_t notifyId,
                        void *);
  void onNotifyModule(const std::string &moduleIdFrom, uint64_t notifyId,
                      void *);
};
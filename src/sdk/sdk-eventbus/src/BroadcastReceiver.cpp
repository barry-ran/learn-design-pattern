#include "BroadcastReceiver.h"
#include <iostream>

bool BroadcastReceiver::Init(
    const std::function<void(const std::string &, uint64_t notifyId, void *)>
        &onModuleReceiver) {
  m_pfnOnModuleReceiver = onModuleReceiver;
  return true;
}

bool BroadcastReceiver::Uninit() { return true; }

bool BroadcastReceiver::RegisterObserver(const std::string &moduleId,
                                         PFNOnModuleNotify observer) {
  if (nullptr == observer) {
    return false;
  }
  std::map<std::string, std::list<PFNOnModuleNotify>>::iterator itFind =
      m_mapNotifyFunction.find(moduleId);
  if (itFind == m_mapNotifyFunction.end()) {
    std::list<PFNOnModuleNotify> lst;
    m_mapNotifyFunction[moduleId] = lst;
    itFind = m_mapNotifyFunction.find(moduleId);
  }
  std::list<PFNOnModuleNotify> &lst = itFind->second;
  lst.push_back(observer);
  return true;
}

bool BroadcastReceiver::RevokeObserver(const char *moduleId,
                                       PFNOnModuleNotify observer) {
  return true;
}

bool BroadcastReceiver::RegisterObserver(const std::string &moduleId,
                                         const std::string &moduleIdObserver) {
  if (0 == moduleId.size() || 0 == moduleIdObserver.size()) {
    return false;
  }
  std::map<std::string, std::list<std::string>>::iterator itFind =
      m_mapNotifyModule.find(moduleId);
  if (itFind == m_mapNotifyModule.end()) {
    std::list<std::string> lst;
    m_mapNotifyModule[moduleId] = lst;
    itFind = m_mapNotifyModule.find(moduleId);
  }
  std::list<std::string> &lst = itFind->second;
  lst.push_back(moduleIdObserver);
  return true;
}

bool BroadcastReceiver::RevokeObserver(const char *moduleId,
                                       const std::string &moduleIdObserver) {
  return true;
}

void BroadcastReceiver::OnModuleNotify(const std::string &moduleIdFrom,
                                       uint64_t notifyId, void *notify) {
  onNotifyFunction(moduleIdFrom, notifyId, notify);
  onNotifyModule(moduleIdFrom, notifyId, notify);
}

void BroadcastReceiver::onNotifyFunction(const std::string &moduleIdFrom,
                                         uint64_t notifyId, void *notify) {
  std::map<std::string, std::list<PFNOnModuleNotify>>::const_iterator itFind =
      m_mapNotifyFunction.find(moduleIdFrom);
  if (itFind == m_mapNotifyFunction.end()) {
    return;
  }
  const std::list<PFNOnModuleNotify> &lst = itFind->second;
  for (std::list<PFNOnModuleNotify>::const_iterator it = lst.begin();
       it != lst.end(); ++it) {
    (*it)(moduleIdFrom.c_str(), notifyId, notify);
  }
}

void BroadcastReceiver::onNotifyModule(const std::string &moduleIdFrom,
                                       uint64_t notifyId, void *notify) {
  std::map<std::string, std::list<std::string>>::const_iterator itFind =
      m_mapNotifyModule.find(moduleIdFrom);
  if (itFind == m_mapNotifyModule.end()) {
    return;
  }
  const std::list<std::string> &lst = itFind->second;
  for (std::list<std::string>::const_iterator it = lst.begin(); it != lst.end();
       ++it) {
    std::string moduleIdTo = *it;
    m_pfnOnModuleReceiver(moduleIdTo, notifyId, notify);
  }
}
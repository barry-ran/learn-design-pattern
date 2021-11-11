#pragma once

#include <mutex>

// notice: Don't abuse Singleton
// https://stackoverflow.com/questions/137975/what-is-so-bad-about-singletons

namespace SDK_COMMON {

template <typename T> class Singleton {
public:
  static T *GetInstance() {
    if (!s_instance) {
      s_instance = new T();
    }
    return s_instance;
  }

  static void DestroyInstance() {
    if (s_instance) {
      delete s_instance;
    }
    s_instance = nullptr;
  }

public:
  Singleton(const Singleton &) = delete;
  Singleton &operator=(const Singleton &) = delete;
  Singleton(Singleton &&) noexcept = delete;
  Singleton &operator=(Singleton &&) noexcept = delete;

protected:
  Singleton() = default;
  virtual ~Singleton() = default;

private:
  static T *s_instance;
};

template <typename T> T *Singleton<T>::s_instance = nullptr;

} // namespace SDK_COMMON

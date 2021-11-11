#pragma once

#ifdef __APPLE__
#define SDK_API __attribute__((visibility("default")))
#else
#define SDK_API __declspec(dllexport)
#endif

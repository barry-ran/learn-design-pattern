#pragma once

#include <cctype>
#include <codecvt>
#include <locale>
#include <regex>
#include <string>
#include <vector>

#ifdef __APPLE__
#include <Foundation/Foundation.h>
#endif

#define CSTYLE_TO_STRING(x) (NULL == x) ? "" : x;

namespace SDK_COMMON {
;

class StringUtil {
public:
  // mac: utf8 -> utf32
  // win: utf8 -> utf16
  static std::wstring Utf8ToUnicode(const std::string &str) {
    std::wstring res;
    try {
      // std::wstring_convert<std::codecvt_utf8<wchar_t>> strCnv;
#ifdef __APPLE__
      std::wstring_convert<std::codecvt_utf8<wchar_t>> strCnv;
#else
      std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> strCnv;
#endif
      res = strCnv.from_bytes(str);
    } catch (...) {
      res.clear();
    }
    return res;
  }

  static std::string UnicodeToUtf8(const std::wstring &wstr) {
    std::string res;
    try {
      std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> strCnv;
      res = strCnv.to_bytes(wstr);
    } catch (...) {
      res.clear();
    }
    return res;
  }

  static std::u16string Utf8ToUtf16(const std::string &str) {
    std::u16string res;
    try {
      std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> strCnv;
      res = strCnv.from_bytes(str);
    } catch (...) {
      res.clear();
    }
    return res;
  }

  static std::string Utf16ToUtf8(const std::u16string &str) {
    std::string res;
    try {
      std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> strCnv;
      res = strCnv.to_bytes(str);
    } catch (...) {
      res.clear();
    }
    return res;
  }

  static std::u32string Utf8ToUtf32(const std::string &str) {
    std::u32string res;
    try {
      std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> strCnv;
      res = strCnv.from_bytes(str);
    } catch (...) {
      res.clear();
    }
    return res;
  }

  static std::string Utf32ToUtf8(const std::u32string &str) {
    std::string res;
    try {
      std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> strCnv;
      res = strCnv.to_bytes(str);
    } catch (...) {
      res.clear();
    }
    return res;
  }
};

} // namespace SDK_COMMON

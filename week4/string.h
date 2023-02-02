#pragma once

#include <cstring>

struct String {
  char * cstr{nullptr};
  size_t len{};

  String(const char * str) {
    len = std::strlen(str);
    cstr = new char[len + 1]{};
    std::strcpy(cstr, str);
  }

  ~String() {
    delete[] cstr;
  }
};

#pragma once

#include <cstring>

struct String {
  char * cstr{nullptr};
  size_t len{};

  // default ctor
  String() : String{""} {}

  // ctor
  String(const char * str) {
    len = std::strlen(str);
    cstr = new char[len + 1]{};
    std::strcpy(cstr, str);
  }

  // copy ctor
  String(const String & other) : String{other.cstr} {}

  // dtor
  ~String() {
    delete[] cstr;
  }

  // copy-assignment
  // s2 = s
  // s2.operator=(s)
  // s2 = s2;
  String& operator=(const String& other) {
    // guard pattern
    if (this == &other) {
      return *this;
    }

    // dtor
    delete[] cstr;

    // ctor
    len = other.len;
    cstr = new char[other.len + 1]{};
    std::strcpy(cstr, other.cstr);

    return *this;
  }
};

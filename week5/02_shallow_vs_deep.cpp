#include <iostream>
#include <cstring>

char * copy(const char * s) {
  auto len = std::strlen(s);
  char * s2 = new char[len + 1]{};
  std::strcpy(s2, s);
  return s2;
}

char ** copy(char ** items, size_t len) {
  char ** newItems = new char * [len]{};
  for (size_t i{}; i < len; ++i) {
    newItems[i] = copy(items[i]);
  }
  return newItems;
}

int main() {
  char s1[]{"hi"};
  char s2[]{"there"};
  char * strs[]{s1, s2};

  char ** strs2 = copy(strs, 2);

  for (size_t i{}; i < 2; ++i) {
    std::cout << strs2[i] << '\n';
  }

  for (size_t i{}; i < 2; ++i) {
    delete[] strs2[i];
  }
  delete[] strs2;
  strs2 = nullptr;
}

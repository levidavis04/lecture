#include <iostream>
#include <cstring>

int main() {
  char ** strs = new char *[3]{};

  for (size_t i{}; i < 3; ++i) {
    char * str = new char[256]{};
    std::strcpy(str, "bob");
    strs[i] = str;
  }

  for (size_t i{}; i < 3; ++i) {
    std::cout << strs[i] << '\n';
  }

  for (size_t i{}; i < 3; ++i) {
    delete[] strs[i];
  }
  delete[] strs;
}

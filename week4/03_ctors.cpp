#include <iostream>
#include "string.h"

int main() {
  String s{"bob"};
  std::cout << s.cstr << '\n';
}

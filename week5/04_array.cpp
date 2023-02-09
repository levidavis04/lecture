#include <iostream>
#include "array.h"

template <typename T, typename F>
void forEach(const T & items, size_t len, F fn) {
  for (size_t i{}; i < len; ++i) {
    std::cout << items[i] << '\n';
  }
}

int main() {
  Array xs{42, 13, 10};

  Array xs2{1, 2, 3};
  xs2 = xs;

  Array xs3{xs};

  for (size_t i{}; i < 3; ++i) {
    std::cout << xs3[i] << '\n';
  }

  forEach(xs3, 3, [](auto item) {
    std::cout << item << '\n';
  });

  float ys[]{42, 37, 55};
  forEach(ys, 3, [](auto item) {
    std::cout << item << '\n';
  });
}

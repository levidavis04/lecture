#include <iostream>

// metaprogramming
template <typename T>
T divide(T x, T y) {
  return x / y;
}

int main() {
  std::cout << divide(3, 2) << '\n';
  std::cout << divide(3.0f, 2.0f) << '\n';
}

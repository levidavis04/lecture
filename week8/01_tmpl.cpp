#include <iostream>

template <typename T>
struct Point {
  T x;
  T y;
};

template <typename T>
auto foo(const Point<T> & p) {
  return p.x / p.y;
}

auto print = [](const auto & p) {
  std::cout << p.x << ' ' << p.y << '\n';
};

int main() {
  Point<double> p{2.5, 3.1};
  foo(p);
  print(p);
}

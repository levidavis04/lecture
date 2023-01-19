#include <iostream>

struct Point {
  int x{};
  int y{};
};

void print(const Point & p) {
  std::cout << p.x << ' ' << p.y << '\n';
}

int main() {
  Point p{42, 1227};
  print(p);
}

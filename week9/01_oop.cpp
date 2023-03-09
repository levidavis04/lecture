#include <iostream>

class Point {
public:
  int x;
  int y;

  Point() {}

  Point(int x, int y): x{x}, y{y} {}

private:
  int w;
};

int main() {
  Point point{2, 3};

  point.x = 42;
  // point.w = 33;

  std::cout << point.x << ' ' << point.y << '\n';
}
#include <iostream>
#include <fstream>

struct Point {
  int x;
  int y;
  int z;
};

int main() {
  std::ifstream f{"myfile.txt"};
  Point p{};
  while (f >> p.x >> p.y >> p.z) {
    auto [a, b, c] = p;
    std::cout << a << ' ' << b << ' ' << c << '\n';
  }
}

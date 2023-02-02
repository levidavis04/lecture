#include <iostream>

/*
 * Fundamental Categories of Data
 * 1. Scalars
 * 2. Lists
 * 3. Bags
 * 4. Functions
 */

struct Point {
  float x;
  float y;

  void print() {
    std::cout << x << ' ' << y << '\n';
  }

  static void info() {
    std::cout << "This is the Point struct.\n";
  }

  // now C++ territory (here be dragons)

  // beginning of life
  Point(float x, float y) {
    this->x = x;
    this->y = y;
    std::cout << "constructor (init, ctor): " << x << ' ' << y << '\n';
  }

  // end of life
  ~Point() {
    std::cout << "destructor (destroy, dtor): " << x << ' ' << y << '\n';
  }
};

int main() { // beginning of life
  Point p{2, 4}; // ctor

  p.x = 23;
  p.y = 50;

  p.print();
  Point::info();

  Point p2{1, 4}; // ctor
  p2.print();
} // end of life, dtor

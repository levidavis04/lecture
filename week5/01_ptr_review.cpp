#include <iostream>

int main() {
  int x{42};

  int * p = &x; // p -> x
  int ** p2 = &p;
  int *** p3 = &p2;

  std::cout << ***p3 << '\n';
}

#include <iostream>

/*
 * Fundamental Categories of Data
 * 1. Scalars (char, double, float, int)
 * 2. Lists (arrays, std::vector)
 * 3. Bags (struct?, std::map)
 * 4. Lambdas
 */

int foo() {
  return 42;
}

void bar(int (*fn)()) {
  std::cout << "calling: " << fn() << '\n';
}

int main() {
  int x{42};
  int * p = &x;

  int xs[]{2, 4, 6};
  int * p2 = xs; // &xs[0]

  int (*p3)();
  p3 = foo;
  p3();
  bar(p3);
}

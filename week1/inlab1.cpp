#include <iostream>

int main() {
  char str[]{"hello\0"};
  const char * str2{"yeet"};

 // std::cout << str << ' ' << str2 << '\n';

  int xs[]{2, 4, 6};

  int * val1 = &xs[1];
  int * val2 = &xs[2]; // & means "address of"

  // print out addresses (RAM indexes)
  std::cout << val1 << ' ' << val2 << '\n';
  // print out values at those indexes (dereference)
  std::cout << *val1 << ' ' << *val2 << '\n';

  double * nums = new double[1000]{}; // dynamic array!

  nums[0] = 42;

  delete [] nums;
}

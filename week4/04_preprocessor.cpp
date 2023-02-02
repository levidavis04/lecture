#include <iostream>

#include "string.h"
#include "string.h"

#define x 42

#define y if (x % 2 == 0) {\
  std::cout << "it is even\n";\
} else {\
  std::cout << "nope\n";\
}

int main() {
  std::cout << x << '\n';

  y
}

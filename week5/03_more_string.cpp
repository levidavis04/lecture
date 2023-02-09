#include <iostream>
#include "string.h"

int main() {
  String s{"bob"};
  std::cout << s.cstr << '\n';

  String s2{"hiya"};

  s2 = s; // syntactic sugar
  // s2.operator=(s);

  s2.cstr[0] = 'l';

  // should still be the same as before!
  std::cout << s.cstr << '\n';

  String s3{s};

  s3.cstr[0] = 'h';

  // should still be the same as before!
  std::cout << s.cstr << '\n';
}

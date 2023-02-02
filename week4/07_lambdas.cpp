#include <iostream>

template <typename F>
void bar(F fn) {
  std::cout << "calling: " << fn() << '\n';
}

int main() {
  int x{42};

  auto inc = [&]() {
    ++x;
    return x;
  };

  // closure
  auto fn = [=]() {
    return 2*x;
  };

  fn();

  bar(fn);
  bar(inc);
  bar(inc);
  bar(fn);

  std::cout << x << '\n';
}

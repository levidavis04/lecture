#include <iostream>

/*

Categories of Data
1. Scalars (int, bool, char, std::string)
2. Lists (std::vector)
3. Bags (std::map)
4. Functions/lambdas

*/

// Rule of Zero
struct Point {
  int x;
  int y;
};

// Rule of Three (Five next term)
struct String {
  char * str{};
  size_t len{};

  // default ctor
  String() : String{"bob"} {
    // ...
  }

  String(const char * s) {

  }

  // dtor
  ~String() {
    // ...
  }

  // copy ctor
  String(const String & other) {
    // ...
  }

  // copy assignment
  String & operator=(const String & other) {
    // ...
    return *this;
  }

  void bar() {

  }
};

void foo(String str) {

}

int main(int argc, char * argv[]) {
  char * str{"bob"};
  char name[]{"bob"};
  char * bob = new char[256]{};
  delete[] bob;

  String s{"bob"};
  String s2{s};
  String s3{};
  s3 = s; // s3.operator=(s)
  s.bar();
}
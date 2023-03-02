#include <iostream>
#include <map>
#include <string>

int main() {
  std::map<std::string, int> myMap{};

  myMap["bob"] = 42;
  myMap["bob"] = 13;

  std::string s{"bob"};
  std::string s2{};
  s2 = s;

  std::cout << myMap["bob"] << '\n';
}

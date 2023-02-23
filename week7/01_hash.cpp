#include <iostream>

// K&R hashing algorithm
size_t hash(const char * str) {
  size_t hash{};
  for (size_t i{}; str[i]; ++i) {
    hash += str[i];
  }
  return hash;
}

// djb2 hash
size_t hash2(const char * str) {
  size_t hash{};
  for (size_t i{}; str[i]; ++i) {
    hash = hash*33 + str[i];
  }
  return hash;
}

int main(int argc, char * argv[]) {
  if (argc != 2) {
    return 1;
  }

  char * str = argv[1];

  int values[100]{};

  std::cout << hash2(str) << '\n';
  std::cout << (hash2(str) % 100) << '\n';
}

#include <iostream>
#include <fstream>
#include <cstring>

int main(int argc, char * argv[]) {
  // guard pattern
  if (argc < 2) {
    std::cerr << "You did not specify a file!\n";
    return 1;
  }

  // RAII = Resource Acquisition Is Initialization
  std::ifstream f{argv[1]}; // ctor!
  // don't do:  f.open, since it breaks RAII!

  if (!f.is_open()) {
    std::cerr << "Could not read file!\n";
    return 1;
  }

  // Scott Meyers: Effective C++

  char line[256]{};
  char lines[1000][256]{};
  size_t len{};
  while (f.getline(line, 255)) {
    // buffer is the line
    strcpy(lines[len], line);
    ++len;
  }
  // there are "i" lines at this point in "lines"

  for (size_t i{}; i < len; ++i) {
    std::cout << lines[i] << '\n';
  }
  // no f.close() because of RAII (dtor)
} // dtor!

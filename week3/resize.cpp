#include <iostream>

void print(int * xs, size_t len) {
  for (size_t i{}; i < len; ++i) {
    std::cout << xs[i] << '\n';
  }
}

// & -> mutable (vs immutable)
void append(int *& items, size_t & len, int newItem) {
  // 1. new array (1 more than the len)
  int * newItems = new int[len + 1]{};
  // 2. copy over the old data
  for (size_t i{}; i < len; ++i) {
    newItems[i] = items[i];
  }
  // 3. copy over the new data
  newItems[len] = newItem;
  // 4. delete old array
  delete[] items;
  // 5. re-assign
  items = newItems;
  ++len;
}

int main() {
  size_t len{3};
  int * xs = new int[len]{2, 4, 6};

  append(xs, len, 8);
  print(xs, len);

  delete[] xs;
}

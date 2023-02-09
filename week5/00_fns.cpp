#include <iostream>

auto print = [](auto x) {
  std::cout << x << '\n';
};

template <typename T, typename F>
void forEach(T items[], size_t len, F fn) {
  for (size_t i{}; i < len; ++i) {
    fn(items[i]);
  }
}

void append(int *& items, size_t & len, int item) {
  // 1. re-alloc a bigger array
  int * newItems = new int[len + 1]{};
  // 2. copy the values
  for (size_t i{}; i < len; ++i) {
    newItems[i] = items[i];
  }
  newItems[len] = item;
  ++len;
  // 3. delete the old array (and re-assign)
  delete[] items;
  items = newItems;
}

/*
template <typename F>
int * map(int * items, size_t len, F fn) {
  int * list{nullptr};
  size_t listSize{};
  forEach(items, len, [](auto item) {
    append(list, listSize, fn(item));
  });
  return list;
}
*/

int main() {
  int xs[]{2, 4, 6, 8};
  forEach(xs, 4, print);

  float nums[]{42.f, 50.f, -121.25f};
  forEach(nums, 3, print);
}

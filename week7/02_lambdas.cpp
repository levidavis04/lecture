#include <iostream>
#include <cstddef>

struct Array {
  int values[4]{1, 2, 3, 4};
  size_t len{4};
};

template <typename F>
void forEach(const Array & items, F fn) {
  for (size_t i{}; i < items.len; ++i) {
    fn(items.values[i]);
  }
}

template <typename F>
auto map(const Array & items, F fn) {
  Array result;
  for (size_t i{}; i < items.len; ++i) {
    result.values[i] = fn(items.values[i]);
  }
  return result;
}

template <typename F>
auto filter(const Array & items, F fn) {
  Array result;
  result.len = 0;
  for (size_t i{}; i < items.len; ++i) {
    if (fn(items.values[i])) {
      result.values[result.len] = items.values[i];
      ++result.len;
    }
  }
  return result;
}

size_t findIndex(const Array & items, int value) {
  for (size_t i{}; i < items.len; ++i) {
    auto item = items.values[i];
    if (value == item) {
      return i;
    }
  }
  return -1;
}

auto includes(const Array & items, int value) {
  return findIndex(items, value) != -1;
}

auto print = [](auto value) {
  std::cout << value << '\n';
};

int main() {
  Array items;

  forEach(items, print);

  auto result = map(items, [](int value) {
    return value*2;
  });

  std::cout << '\n';
  forEach(result, print);

  std::cout << '\n';
  auto result2 = filter(items, [](int value) {
    return value % 2 == 0;
  });
  forEach(result2, print);

  std::cout << '\n';
  auto haveIt = includes(items, 4);
  std::cout << haveIt << '\n';
}

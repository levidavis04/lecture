#include <iostream>
#include <vector>

template <typename T, typename F>
void forEach(const std::vector<T> & items, F fn) {
  for (auto & item : items) {
    fn(item);
  }
}

template <typename T, typename F>
auto map(const std::vector<T> & items, F fn) {
  using K = std::invoke_result_t<F, T>;

  std::vector<K> newItems{};
  forEach(items, [](auto item) {
    auto newItem = fn(item);
    newItems.push_back(newItem);
  });
  return newItems;
}

template <typename T, typename F>
size_t findIndex(const std::vector<T> & items, const T & item) {
  for (size_t i{}; i < items.size(); ++i) {
    if (items[i] == item) {
      return i;
    }
  }
  return -1;
}

template <typename T>
auto concat(const std::vector<T> & a, const std::vector<T> & b) {
  std::vector<T> c{a};
  for (auto item : b) {
    c.push_back(item);
  }
  return c;
}

auto print = [](auto item) {
  std::cout << item << '\n';
};

int main() {
  std::vector<int> items{};

  items.push_back(23);
  items.push_back(42);

  forEach(items, print);

  auto newItems = map(items, [](auto item) {
    return item % 2 == 0 ? 2*item : item;
  });

  std::cout << '\n';
  forEach(newItems, print);
}

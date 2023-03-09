#include <iostream>

struct Node {
  int data{};
  Node * next{};
};

struct List {
  Node * head{};
  Node * tail{};
};

void append(List & list, int data) {
  Node * item = new Node{data};

  if (list.head == nullptr) {
    list.head = item;
    list.tail = item;
  } else {
    list.tail->next = item;
    list.tail = list.tail->next;
  }
}

template <typename F>
void forEach(const List & list, F fn) {
  Node * p{list.head};
  while (p) {
    fn(p->data);
    p = p->next;
  }
}

auto print = [](const auto & item) {
  std::cout << item << '\n';
};

int main() {
  List list{};

/*
  // add our first item
  Node * item1 = new Node{42};
  list.head = item1;
  list.tail = item1;

  // add a second item
  Node * item2 = new Node{1337};
  list.tail->next = item2;
  list.tail = list.tail->next;

  // add a third item
  Node * item3 = new Node{37};
  list.tail->next = item3;
  list.tail = list.tail->next;
*/

  append(list, 42);
  append(list, 1337);
  append(list, 37);

  forEach(list, print);
}
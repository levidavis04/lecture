#include <iostream>
#include <cstring>
#include "string.h"

struct Node {
  int data{};
  Node * next{};

  Node() = default;
  Node(int data) : data{data} {}
  Node(const Node & other) : data{other.data}, next{other.next ? new Node(*other.next) : nullptr} {}
  Node & operator=(const Node & other) {
    if (this != &other) {
      data = other.data;
      delete next;
      next = other.next ? new Node(*other.next) : nullptr;
    }
    return *this;
  }
  ~Node() {
    delete next;
  }
};

struct List {
  Node * head{};
  Node * tail{};

  List() = default;
  List(const List & other) : head{other.head ? new Node(*other.head) : nullptr}, tail{other.tail} {}
  List & operator=(const List & other) {
    if (this != &other) {
      delete head;
      head = other.head ? new Node(*other.head) : nullptr;
      tail = other.tail;
    }
    return *this;
  }
  ~List() {
    delete head;
  }
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

  append(list, 42);
  append(list, 1337);
  append(list, 37);

  forEach(list, print);
}

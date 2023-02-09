#pragma once

struct Array {
  int * xs{};
  size_t len{};

  Array(int x, int y, int z) {
    xs = new int[3]{};
    xs[0] = x;
    xs[1] = y;
    xs[2] = z;
    len = 3;
  }

  // dtor
  ~Array() {
    delete[] xs;
  }

  // copy-assignment
  Array & operator=(const Array & other) {
    if (this == &other) {
      return *this;
    }

    // dtor
    delete[] xs;

    // ctor
    xs = new int[3]{};
    xs[0] = other.xs[0];
    xs[1] = other.xs[1];
    xs[2] = other.xs[2];
    len = 3;

    return *this;
  }

  // copy ctor
  Array(const Array & other) : Array{other.xs[0], other.xs[1], other.xs[2]} { }

  int & operator[](size_t i) {
    return xs[i];
  }

  const int & operator[](size_t i) const {
    return xs[i];
  }
};

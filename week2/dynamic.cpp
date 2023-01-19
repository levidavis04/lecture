#include <iostream>
#include <iomanip>

size_t strlen(const char * s) {
  size_t i{};
  for (; s[i]; ++i) { }
  return i;
}

// int x{42};
// int y{};
// y = x;
void strcpy(char * dest, const char * src) {
  size_t i{};
  for (; src[i]; ++i) {
    dest[i] = src[i];
  }
  dest[i] = '\0';
}

// int x{42};
// int y{x};
char * strdup(const char * s) {
  char * s2 = new char[strlen(s) + 1]{};
  strcpy(s2, s);
  return s2;
}

// int x{42};
// int y{1337};
// x == y
bool streq(const char * s1, const char * s2) {
  for (size_t i{}; s1[i] || s2[i]; ++i) {
    if (s1[i] != s2[i]) {
      return false;
    }
  }
  return true;
}

/*
{
  const char * strs[]{"bob", "hi", "yo"};
  char strs2[3][100]{};

  char ** strs3 = new char * [5]{};
  for (size_t i{}; i < 5; ++i) {
    strs3[i] = new char[23]{};
  }

  for (size_t i{}; i < 5; ++i) {
    delete[] strs3[i];
  }

  delete[] strs3;
}
*/
// loop through argv, duplicating on the heap (strdup)
//   check if any of them are duplicates (hint: streq)
int main(int argc, char * argv[]) {
  const char * s{"hello, world"};
  char * args[argc]{};

  char * s2 = strdup(s); // new c-string on the heap

  std::cout << s2 << '\n';
  std::cout << std::boolalpha << streq(s, s2) << '\n';

  delete[] s2;
}

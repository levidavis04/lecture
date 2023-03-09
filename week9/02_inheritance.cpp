#include <iostream>
#include <string>

class Animal {
protected:
  std::string name{};

public:
  Animal() : Animal{"animal"} {}

  Animal(const std::string & name) : name{name} {}

  void speak() {
    std::cout << "The " << name << " says hi\n";
  }
};

class Dog : public Animal {
public:
  Dog() : Animal{"dog"} {}

  Dog(const std::string & name) : Animal{name} {}

  void jump() {
    std::cout << name << " is jumping!\n";
  }
};

class Pug : public Dog {
public:
  Pug() : Dog{"pug"} {}
};

class Cat : public Animal {
public:
  Cat() : Animal{"cat"} {}
};

int main() {
  Animal animal{}; // now an object
  animal.speak();

  Dog dog{};
  dog.speak();

  Pug pug{};
  pug.speak();
  pug.jump();

  Cat cat{};
  cat.speak();
}
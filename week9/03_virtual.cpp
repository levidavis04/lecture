#include <iostream>
#include <string>
#include <vector>

class Animal {
protected:
  std::string name{};

public:
  Animal() : Animal{"animal"} {}

  Animal(const std::string & name) : name{name} {}

  virtual void speak() {
    std::cout << "The " << name << " says hi\n";
  }
};

class Dog : public Animal {
public:
  Dog() : Animal{"dog"} {}

  Dog(const std::string & name) : Animal{name} {}

  void speak() override {
    std::cout << "woof woof!\n";
  }

  void jump() {
    std::cout << name << " is jumping!\n";
  }
};

class Pug : public Dog {
public:
  Pug() : Dog{"pug"} {}

  void speak() override {
    std::cout << "...snort...\n";
  }
};

class Cat : public Animal {
public:
  Cat() : Animal{"cat"} {}

  void speak() override {
    std::cout << "back, you slave!\n";
  }
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

  std::cout << "\n------\n\n";

  Animal * animal1 = &dog;
  animal1->speak();

  Animal & animal2 = pug;
  animal2.speak();

  std::cout << "\n------\n\n";

  std::vector<Animal *> animals{};
  animals.push_back(&dog);
  animals.push_back(&cat);
  animals.push_back(&pug);

  for (Animal * animal : animals) {
    animal->speak();
  }
}
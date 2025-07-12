#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    virtual void makeSound() {
        cout << "Some generic animal sound" << endl;
    }

    virtual ~Animal() {}
};

// Derived class: Dog
class Dog : public Animal {
public:
    void makeSound() override {
        cout << "Bark" << endl;
    }
};

// Derived class: Cat
class Cat : public Animal {
public:
    void makeSound() override {
        cout << "Meow" << endl;
    }
};

// Derived class: Cow
class Cow : public Animal {
public:
    void makeSound() override {
        cout << "Moo" << endl;
    }
};

int main() {
    Animal* animals[3];
    animals[0] = new Dog();
    animals[1] = new Cat();
    animals[2] = new Cow();

    for (int i = 0; i < 3; i++) {
        animals[i]->makeSound();  // Calls the correct derived class version
    }

    // Clean up
    for (int i = 0; i < 3; i++) {
        delete animals[i];
    }

    return 0;
}

#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    virtual void speak() const {
        cout << "Animal makes a sound." << endl;
    }
    virtual ~Animal() {} // Virtual destructor for proper cleanup
};

// Derived class: Dog
class Dog : public Animal {
public:
    void speak() const override {
        cout << "Dog says: Woof!" << endl;
    }
};

// Derived class: Cat
class Cat : public Animal {
public:
    void speak() const override {
        cout << "Cat says: Meow!" << endl;
    }
};

// Derived class: Bird
class Bird : public Animal {
public:
    void speak() const override {
        cout << "Bird says: Tweet!" << endl;
    }
};

// Example usage
int main() {
    Animal* animal;

    animal = new Dog();
    animal->speak();  // Output: Dog says: Woof!
    delete animal;

    animal = new Cat();
    animal->speak();  // Output: Cat says: Meow!
    delete animal;

    animal = new Bird();
    animal->speak();  // Output: Bird says: Tweet!
    delete animal;

    return 0;
}

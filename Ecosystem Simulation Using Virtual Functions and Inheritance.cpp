#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Base class Animal (Polymorphism via virtual function)
class Animal {
public:
    // Virtual function to simulate the sound made by the animal
    virtual void makeSound() const {
        cout << "Some generic animal sound!" << endl;
    }

    // Virtual function to simulate the movement of the animal
    virtual void move() const {
        cout << "The animal is moving." << endl;
    }

    // Virtual destructor to ensure proper cleanup
    virtual ~Animal() {
        cout << "Animal destroyed." << endl;
    }
};

// Derived class: Lion
class Lion : public Animal {
public:
    // Overriding the makeSound function
    void makeSound() const override {
        cout << "Roar! I am the king of the jungle!" << endl;
    }

    // Overriding the move function
    void move() const override {
        cout << "The lion prowls through the grass." << endl;
    }

    ~Lion() {
        cout << "Lion destroyed." << endl;
    }
};

// Derived class: Elephant
class Elephant : public Animal {
public:
    // Overriding the makeSound function
    void makeSound() const override {
        cout << "Trumpet! I am the giant of the savannah!" << endl;
    }

    // Overriding the move function
    void move() const override {
        cout << "The elephant lumbers through the forest." << endl;
    }

    ~Elephant() {
        cout << "Elephant destroyed." << endl;
    }
};

// Derived class: Bird
class Bird : public Animal {
public:
    // Overriding the makeSound function
    void makeSound() const override {
        cout << "Chirp! I am flying high!" << endl;
    }

    // Overriding the move function
    void move() const override {
        cout << "The bird soars through the sky." << endl;
    }

    ~Bird() {
        cout << "Bird destroyed." << endl;
    }
};

// Ecosystem simulation class
class Ecosystem {
private:
    vector<Animal*> animals;

public:
    // Add an animal to the ecosystem
    void addAnimal(Animal* animal) {
        animals.push_back(animal);
    }

    // Simulate actions of all animals in the ecosystem
    void simulate() const {
        cout << "Simulating the ecosystem..." << endl;
        for (const auto& animal : animals) {
            animal->makeSound();
            animal->move();
        }
    }

    // Destructor to clean up dynamically allocated memory
    ~Ecosystem() {
        for (auto& animal : animals) {
            delete animal;
        }
        cout << "Ecosystem destroyed." << endl;
    }
};

// Main function to run the simulation
int main() {
    Ecosystem ecosystem;

    // Create and add different animals to the ecosystem
    ecosystem.addAnimal(new Lion());
    ecosystem.addAnimal(new Elephant());
    ecosystem.addAnimal(new Bird());

    // Simulate the ecosystem (animals interacting)
    ecosystem.simulate();

    return 0;
}

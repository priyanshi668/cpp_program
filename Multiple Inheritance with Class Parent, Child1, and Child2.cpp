#include <iostream>
#include <string>
using namespace std;

// Base class Parent
class Parent {
protected:
    string parentName;

public:
    // Constructor to initialize parent's name
    Parent(string name) : parentName(name) {}

    // Method to display parent's name
    void displayParentName() const {
        cout << "Parent's Name: " << parentName << endl;
    }
};

// Derived class Child1 inherits from Parent
class Child1 : public Parent {
protected:
    string child1Name;

public:
    // Constructor to initialize both parent's and child's name
    Child1(string pName, string cName) : Parent(pName), child1Name(cName) {}

    // Method to display child's name (Child1)
    void displayChild1Name() const {
        cout << "Child1's Name: " << child1Name << endl;
    }
};

// Derived class Child2 inherits from Parent
class Child2 : public Parent {
protected:
    string child2Name;

public:
    // Constructor to initialize both parent's and child's name
    Child2(string pName, string cName) : Parent(pName), child2Name(cName) {}

    // Method to display child's name (Child2)
    void displayChild2Name() const {
        cout << "Child2's Name: " << child2Name << endl;
    }
};

// Derived class that demonstrates multiple inheritance
class Child : public Child1, public Child2 {
public:
    // Constructor to initialize both Parent and Child class names
    Child(string pName, string c1Name, string c2Name)
        : Parent(pName), Child1(pName, c1Name), Child2(pName, c2Name) {}

    // Method to display all names (Parent and both children)
    void displayAllNames() const {
        displayParentName();
        displayChild1Name();
        displayChild2Name();
    }
};

int main() {
    // Create a Child object
    Child child("John", "Alice", "Bob");

    // Display the names
    child.displayAllNames();

    return 0;
}

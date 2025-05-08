#include <iostream>
using namespace std;

// Base class
class Employee {
public:
    virtual void displayRole() const {
        cout << "I am an employee." << endl;
    }

    virtual ~Employee() {} // Virtual destructor for proper cleanup
};

// Derived class: Manager
class Manager : public Employee {
public:
    void displayRole() const override {
        cout << "I am a manager. I oversee teams." << endl;
    }
};

// Derived class: Worker
class Worker : public Employee {
public:
    void displayRole() const override {
        cout << "I am a worker. I perform assigned tasks." << endl;
    }
};

// Example usage
int main() {
    Employee* emp;

    emp = new Employee();
    emp->displayRole();  // Output: I am an employee.
    delete emp;

    emp = new Manager();
    emp->displayRole();  // Output: I am a manager. I oversee teams.
    delete emp;

    emp = new Worker();
    emp->displayRole();  // Output: I am a worker. I perform assigned tasks.
    delete emp;

    return 0;
}

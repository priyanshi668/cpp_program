#include <iostream>
#include <string>
using namespace std;

// Base class Person
class Person {
protected:
    string name;
    int age;

public:
    // Constructor to initialize name and age
    Person(string n, int a) : name(n), age(a) {}

    // Method to display personal details
    void display() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

// Derived class Employee inherits from Person
class Employee : public Person {
private:
    string position;
    double salary;

public:
    // Constructor to initialize name, age, position, and salary
    Employee(string n, int a, string p, double s)
        : Person(n, a), position(p), salary(s) {}

    // Method to display employee details
    void displayEmployeeDetails() const {
        display();  // Call the base class method to display name and age
        cout << "Position: " << position << endl;
        cout << "Salary: $" << salary << endl;
    }
};

int main() {
    // Create an Employee object
    Employee emp("John Doe", 30, "Software Engineer", 85000);

    // Display employee details
    emp.displayEmployeeDetails();

    return 0;
}

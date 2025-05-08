#include <iostream>
#include <string>
using namespace std;

// Abstract base class Employee
class Employee {
public:
    // Pure virtual function to calculate salary
    virtual double calculateSalary() const = 0;

    // Pure virtual function to display employee details
    virtual void displayDetails() const = 0;

    // Virtual destructor to allow proper cleanup of derived class objects
    virtual ~Employee() {}
};

// Derived class Manager
class Manager : public Employee {
private:
    string name;
    double baseSalary;
    double bonus;

public:
    // Constructor to initialize Manager details
    Manager(string n, double bSalary, double b) : name(n), baseSalary(bSalary), bonus(b) {}

    // Implement the calculateSalary function
    double calculateSalary() const override {
        return baseSalary + bonus;  // Salary = baseSalary + bonus
    }

    // Implement the displayDetails function
    void displayDetails() const override {
        cout << "Manager: " << name << endl;
        cout << "Base Salary: $" << baseSalary << ", Bonus: $" << bonus << endl;
        cout << "Total Salary: $" << calculateSalary() << endl;
    }
};

// Derived class Engineer
class Engineer : public Employee {
private:
    string name;
    double baseSalary;
    double overtimePay;

public:
    // Constructor to initialize Engineer details
    Engineer(string n, double bSalary, double overtime) : name(n), baseSalary(bSalary), overtimePay(overtime) {}

    // Implement the calculateSalary function
    double calculateSalary() const override {
        return baseSalary + overtimePay;  // Salary = baseSalary + overtimePay
    }

    // Implement the displayDetails function
    void displayDetails() const override {
        cout << "Engineer: " << name << endl;
        cout << "Base Salary: $" << baseSalary << ", Overtime Pay: $" << overtimePay << endl;
        cout << "Total Salary: $" << calculateSalary() << endl;
    }
};

int main() {
    // Create objects of Manager and Engineer
    Employee* manager = new Manager("Alice", 50000, 10000);  // Manager with base salary and bonus
    Employee* engineer = new Engineer("Bob", 40000, 5000);  // Engineer with base salary and overtime pay

    // Display details of each employee
    manager->displayDetails();  // Displays Manager details
    cout << endl;
    engineer->displayDetails();  // Displays Engineer details

    // Deallocate memory
    delete manager;
    delete engineer;

    return 0;
}

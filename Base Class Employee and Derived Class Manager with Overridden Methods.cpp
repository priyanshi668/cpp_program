#include <iostream>
#include <string>
using namespace std;

// Base class Employee
class Employee {
protected:
    string name;
    double salary;

public:
    // Constructor to initialize Employee details
    Employee(string empName, double empSalary) : name(empName), salary(empSalary) {}

    // Virtual method to display employee details
    virtual void displayDetails() const {
        cout << "Employee Name: " << name << endl;
        cout << "Employee Salary: $" << salary << endl;
    }

    // Virtual destructor
    virtual ~Employee() {}
};

// Derived class Manager
class Manager : public Employee {
private:
    string department;

public:
    // Constructor to initialize Manager details
    Manager(string empName, double empSalary, string dept)
        : Employee(empName, empSalary), department(dept) {}

    // Overridden method to display manager details
    void displayDetails() const override {
        cout << "Manager Name: " << name << endl;
        cout << "Manager Salary: $" << salary << endl;
        cout << "Department: " << department << endl;
    }
};

int main() {
    // Create an Employee object
    Employee emp("John Doe", 50000);
    // Create a Manager object
    Manager mgr("Alice Smith", 80000, "HR");

    // Display employee details
    cout << "Employee Details:" << endl;
    emp.displayDetails();

    // Display manager details
    cout << "\nManager Details:" << endl;
    mgr.displayDetails();

    // Using base class pointer to display details of Manager
    Employee* empPtr = &mgr;
    cout << "\nManager Details using base class pointer:" << endl;
    empPtr->displayDetails();

    return 0;
}

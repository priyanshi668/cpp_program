#include <iostream>
using namespace std;

class Employee {
private:
    string name;
    string position;
    double salary;

public:
    // Constructor
    Employee(string n, string p, double s) {
        name = n;
        position = p;
        salary = s;
    }

    // Method to display employee details
    void displayDetails() {
        cout << "Employee Details:" << endl;
        cout << "Name: " << name << endl;
        cout << "Position: " << position << endl;
        cout << "Salary: $" << salary << endl;
    }
};

int main() {
    // Create an Employee object
    Employee emp("John Doe", "Manager", 75000.00);

    // Display employee details
    emp.displayDetails();

    return 0;
}

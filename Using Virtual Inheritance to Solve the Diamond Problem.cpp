#include <iostream>
using namespace std;

// Base class
class Person {
public:
    Person() {
        cout << "Person constructor called\n";
    }

    void showPerson() {
        cout << "I am a Person.\n";
    }
};

// First-level derived classes using virtual inheritance
class Student : virtual public Person {
public:
    Student() {
        cout << "Student constructor called\n";
    }

    void showStudent() {
        cout << "I am a Student.\n";
    }
};

class Employee : virtual public Person {
public:
    Employee() {
        cout << "Employee constructor called\n";
    }

    void showEmployee() {
        cout << "I am an Employee.\n";
    }
};

// Bottom-level derived class
class WorkingStudent : public Student, public Employee {
public:
    WorkingStudent() {
        cout << "WorkingStudent constructor called\n";
    }

    void show() {
        showPerson();     // No ambiguity due to virtual inheritance
        showStudent();
        showEmployee();
    }
};

// Main function
int main() {
    WorkingStudent ws;

    cout << "\n--- Displaying Info ---\n";
    ws.show();

    return 0;
}

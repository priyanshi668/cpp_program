#include <iostream>
#include <string>
using namespace std;

// Class definition
class Student {
private:
    string name;
    int age;
    double grade;

public:
    // Constructor to initialize data members
    Student(string n, int a, double g) : name(n), age(a), grade(g) {}

    // Member function that uses a pointer to the object to display details
    void displayInfo() const {
        cout << "Student Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Grade: " << grade << endl;
    }

    // Member function that modifies the object data via a pointer
    void modifyInfo(Student* ptr, const string& newName, int newAge, double newGrade) {
        ptr->name = newName;  // Accessing and modifying using pointer to the object
        ptr->age = newAge;
        ptr->grade = newGrade;
    }
};

int main() {
    // Creating a Student object dynamically using new
    Student* studentPtr = new Student("John Doe", 20, 85.5);

    // Displaying original student info
    cout << "Original Student Info:" << endl;
    studentPtr->displayInfo();

    // Modifying student info using a pointer to the object
    studentPtr->modifyInfo(studentPtr, "Alice Smith", 22, 92.0);

    // Displaying updated student info
    cout << "\nUpdated Student Info:" << endl;
    studentPtr->displayInfo();

    // Deallocate memory
    delete studentPtr;

    return 0;
}

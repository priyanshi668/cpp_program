#include <iostream>
#include <string>
using namespace std;

// Class definition
class Student {
private:
    string name;
    int age;
    int grade;

public:
    // Constructor to initialize the data members
    Student(string n, int a, int g) : name(n), age(a), grade(g) {}

    // Method to display student information
    void displayInfo() const {
        cout << "Student Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Grade: " << grade << endl;
    }

    // Getter methods
    string getName() const { return name; }
    int getAge() const { return age; }
    int getGrade() const { return grade; }

    // Setter methods
    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }
    void setGrade(int g) { grade = g; }
};

int main() {
    // Dynamically create an object of Student using 'new'
    Student* studentPtr = new Student("John Doe", 20, 90);

    // Accessing members using the pointer
    cout << "Using pointer to access student details:" << endl;
    studentPtr->displayInfo();  // Display student info

    // Accessing individual members using getter methods
    cout << "\nStudent Details (using getter methods):" << endl;
    cout << "Name: " << studentPtr->getName() << endl;
    cout << "Age: " << studentPtr->getAge() << endl;
    cout << "Grade: " << studentPtr->getGrade() << endl;

    // Modify the student's grade using setter method
    studentPtr->setGrade(95);
    cout << "\nUpdated Grade: " << studentPtr->getGrade() << endl;

    // Deallocate the dynamically allocated memory
    delete studentPtr;

    return 0;
}

#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int age;
    static int totalStudents;  // Static data member to track total students

public:
    // Constructor to initialize student data and increment totalStudents
    Student(string n, int a) {
        name = n;
        age = a;
        totalStudents++;
    }

    // Static method to get total number of students
    static int getTotalStudents() {
        return totalStudents;
    }
};

// Initialize the static member
int Student::totalStudents = 0;

int main() {
    // Creating student objects
    Student student1("Alice", 20);
    Student student2("Bob", 22);
    Student student3("Charlie", 21);

    // Displaying total number of students enrolled
    cout << "Total number of students enrolled: " << Student::getTotalStudents() << endl;

    return 0;
}

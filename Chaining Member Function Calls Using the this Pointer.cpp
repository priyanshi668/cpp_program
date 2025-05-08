#include <iostream>
#include <string>
using namespace std;

// Class definition for Person
class Person {
private:
    string name;
    int age;

public:
    // Constructor to initialize Person's details
    Person(string n, int a) : name(n), age(a) {}

    // Member function to set the name, and return the current object (this pointer)
    Person& setName(const string& n) {
        name = n;
        return *this;  // Return the current object using the this pointer
    }

    // Member function to set the age, and return the current object (this pointer)
    Person& setAge(int a) {
        age = a;
        return *this;  // Return the current object using the this pointer
    }

    // Member function to display the details of the person
    void displayInfo() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    // Create a Person object
    Person person("John Doe", 25);

    // Chain member functions to modify Person details and then display them
    person.setName("Alice Smith").setAge(30).displayInfo();

    return 0;
}

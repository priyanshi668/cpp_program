#include <iostream>
#include <string>
using namespace std;

// Virtual base class Entity
class Entity {
public:
    virtual void display() const = 0; // Pure virtual function to display details
    virtual ~Entity() {} // Virtual destructor
};

// Derived class Person
class Person : public virtual Entity {
private:
    string name;
    int age;

public:
    // Constructor to initialize Person details
    Person(string personName, int personAge) : name(personName), age(personAge) {}

    // Overridden display function to display Person details
    void display() const override {
        cout << "Person Name: " << name << endl;
        cout << "Person Age: " << age << endl;
    }
};

// Derived class Organization
class Organization : public virtual Entity {
private:
    string orgName;
    string industry;

public:
    // Constructor to initialize Organization details
    Organization(string name, string industryType) : orgName(name), industry(industryType) {}

    // Overridden display function to display Organization details
    void display() const override {
        cout << "Organization Name: " << orgName << endl;
        cout << "Industry: " << industry << endl;
    }
};

int main() {
    // Create Person and Organization objects
    Person person("John Doe", 30);
    Organization org("Tech Innovations", "Technology");

    // Display details of Person and Organization
    cout << "Person Details:" << endl;
    person.display();

    cout << "\nOrganization Details:" << endl;
    org.display();

    return 0;
}

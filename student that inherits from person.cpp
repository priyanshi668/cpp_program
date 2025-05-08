#include <iostream>
using namespace std;

class Person {
private:
    string name;
    int age;

public:
    void setName(string n) {
        name = n;
    }

    string getName() {
        return name;
    }

    void setAge(int a) {
        age = a;
    }

    int getAge() {
        return age;
    }
};

class Student : public Person {
private:
    string studentID;

public:
    void setStudentID(string id) {
        studentID = id;
    }

    string getStudentID() {
        return studentID;
    }
};

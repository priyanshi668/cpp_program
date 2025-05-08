#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// Define a complex data structure
struct Employee {
    int id;
    char name[50];
    double salary;
};

int main() {
    const char* filename = "employees.dat";

    // --- Writing to Binary File ---
    {
        ofstream outFile(filename, ios::binary);
        if (!outFile) {
            cerr << "Error: Could not open file for writing." << endl;
            return 1;
        }

        Employee e1 = {101, "Alice Johnson", 55000.50};
        Employee e2 = {102, "Bob Smith", 62000.75};

        outFile.write(reinterpret_cast<char*>(&e1), sizeof(Employee));
        outFile.write(reinterpret_cast<char*>(&e2), sizeof(Employee));

        outFile.close();
        cout << "Employee records written to binary file.\n";
    }

    // --- Reading from Binary File ---
    {
        ifstream inFile(filename, ios::binary);
        if (!inFile) {
            cerr << "Error: Could not open file for reading." << endl;
            return 1;
        }

        Employee emp;
        cout << "\nReading employee records from file:\n";
        while (inFile.read(reinterpret_cast<char*>(&emp), sizeof(Employee))) {
            cout << "ID: " << emp.id << ", Name: " << emp.name
                 << ", Salary: $" << emp.salary << endl;
        }

        inFile.close();
    }

    return 0;
}

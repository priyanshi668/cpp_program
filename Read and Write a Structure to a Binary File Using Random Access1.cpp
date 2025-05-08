#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// Define a structure to store the details of a person
struct Person {
    char name[50];
    int age;
};

// Function to display the details of a Person object
void displayPerson(const Person& p) {
    cout << "Name: " << p.name << endl;
    cout << "Age: " << p.age << endl;
}

// Function to write a Person record to a binary file at a specific position
void writePerson(fstream& file, int position, const Person& p) {
    file.seekp(position * sizeof(Person), ios::beg);  // Seek to the correct position in the file
    file.write(reinterpret_cast<const char*>(&p), sizeof(p));  // Write the Person structure to the file
}

// Function to read a Person record from a binary file at a specific position
void readPerson(fstream& file, int position, Person& p) {
    file.seekg(position * sizeof(Person), ios::beg);  // Seek to the correct position in the file
    file.read(reinterpret_cast<char*>(&p), sizeof(p));  // Read the Person structure from the file
}

int main() {
    const char* filename = "people.dat";

    // --- Writing Data to the Binary File ---
    {
        Person people[3] = {{"Alice", 30}, {"Bob", 25}, {"Charlie", 35}};

        // Open the file for writing in binary mode
        ofstream outFile(filename, ios::out | ios::binary);  
        if (!outFile) {
            cerr << "Error: Could not open the file for writing." << endl;
            return 1;
        }

        // Write each Person object at specific positions
        for (int i = 0; i < 3; i++) {
            writePerson(outFile, i, people[i]);  // Write each person at position i
        }

        outFile.close();
        cout << "Data written to the file." << endl;
    }

    // --- Reading Data Using Random Access ---
    {
        fstream file(filename, ios::in | ios::out | ios::binary);  // Open the file for random access in binary mode
        if (!file) {
            cerr << "Error: Could not open the file for reading and writing." << endl;
            return 1;
        }

        Person person;

        // Read and display the first record
        readPerson(file, 0, person);
        cout << "\nReading the first record:\n";
        displayPerson(person);

        // Read and display the second record
        readPerson(file, 1, person);
        cout << "\nReading the second record:\n";
        displayPerson(person);

        // Read and display the third record
        readPerson(file, 2, person);
        cout << "\nReading the third record:\n";
        displayPerson(person);

        file.close();
    }

    return 0;
}

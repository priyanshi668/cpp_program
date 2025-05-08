#include <iostream>
#include <fstream>

using namespace std;

struct Person {
    char name[50];
    int age;
};

int main() {
    const char* filename = "person.dat";

    // --- Writing to the file in binary mode ---
    {
        Person person1 = {"Alice", 30};

        ofstream outFile(filename, ios::binary);  // Open file for binary writing
        if (!outFile) {
            cerr << "Error: Could not open the file for writing." << endl;
            return 1;
        }

        // Write the Person struct to the file in binary mode
        outFile.write(reinterpret_cast<char*>(&person1), sizeof(person1));
        outFile.close();
        cout << "Data written to file in binary mode." << endl;
    }

    // --- Reading from the file in binary mode ---
    {
        Person person2;

        ifstream inFile(filename, ios::binary);  // Open file for binary reading
        if (!inFile) {
            cerr << "Error: Could not open the file for reading." << endl;
            return 1;
        }

        // Read the Person struct from the file in binary mode
        inFile.read(reinterpret_cast<char*>(&person2), sizeof(person2));
        inFile.close();

        // Display the data read from the file
        cout << "\nData read from file in binary mode:\n";
        cout << "Name: " << person2.name << endl;
        cout << "Age: " << person2.age << endl;
    }

    return 0;
}

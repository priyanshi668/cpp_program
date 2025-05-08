#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Person {
    char name[50];
    int age;
};

// Function to display the details of a Person object
void displayPerson(const Person& p) {
    cout << "Name: " << p.name << endl;
    cout << "Age: " << p.age << endl;
}

int main() {
    const char* filename = "people.dat";

    // --- Writing Data to the File ---
    {
        Person people[3] = {{"Alice", 30}, {"Bob", 25}, {"Charlie", 35}};

        ofstream outFile(filename, ios::out | ios::binary);  // Open file in binary mode for writing
        if (!outFile) {
            cerr << "Error: Could not open the file for writing." << endl;
            return 1;
        }

        // Write the Person structs to the file sequentially
        for (int i = 0; i < 3; i++) {
            outFile.write(reinterpret_cast<char*>(&people[i]), sizeof(people[i]));
        }
        outFile.close();
        cout << "Data written to the file." << endl;
    }

    // --- Reading and Modifying Data Using Random Access ---
    {
        fstream file(filename, ios::in | ios::out | ios::binary);  // Open file for reading and writing in binary mode
        if (!file) {
            cerr << "Error: Could not open the file for random access." << endl;
            return 1;
        }

        // Move to the second person's position (the second record, 1-based index) in the file
        file.seekg(sizeof(Person), ios::beg);  // Move to the second record
        file.seekp(sizeof(Person), ios::beg);  // Move to the second record for writing

        Person person;
        file.read(reinterpret_cast<char*>(&person), sizeof(person));  // Read the second record
        cout << "\nData before modification (second person):\n";
        displayPerson(person);

        // Modify the data of the second person
        strcpy(person.name, "Bobby");
        person.age = 26;

        // Write the modified data back to the same position in the file
        file.seekp(sizeof(Person), ios::beg);  // Move back to the second record for writing
        file.write(reinterpret_cast<char*>(&person), sizeof(person));  // Write the modified person data

        // Move to the last person's position in the file and read the data
        file.seekg(2 * sizeof(Person), ios::beg);  // Move to the third record
        file.read(reinterpret_cast<char*>(&person), sizeof(person));  // Read the third record
        cout << "\nData after modification (third person):\n";
        displayPerson(person);

        file.close();
    }

    // --- Reading Data After Modification ---
    {
        ifstream inFile(filename, ios::in | ios::binary);  // Open the file for reading
        if (!inFile) {
            cerr << "Error: Could not open the file for reading." << endl;
            return 1;
        }

        // Read all the data and display it
        Person person;
        cout << "\nReading the updated data from the file:\n";
        while (inFile.read(reinterpret_cast<char*>(&person), sizeof(person))) {
            displayPerson(person);
        }

        inFile.close();
    }

    return 0;
}

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

// Function to update a specific record in the binary file
void updatePersonRecord(fstream& file, int recordIndex, const Person& newPerson) {
    // Calculate the byte offset for the record (recordIndex * size of Person)
    file.seekp(recordIndex * sizeof(Person), ios::beg);
    
    // Write the updated Person data at the calculated position
    file.write(reinterpret_cast<const char*>(&newPerson), sizeof(newPerson));
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
            outFile.write(reinterpret_cast<const char*>(&people[i]), sizeof(people[i]));
        }
        outFile.close();
        cout << "Data written to the file." << endl;
    }

    // --- Updating Specific Records ---
    {
        fstream file(filename, ios::in | ios::out | ios::binary);  // Open file for random access in binary mode
        if (!file) {
            cerr << "Error: Could not open the file for reading and writing." << endl;
            return 1;
        }

        // Prepare new data for the second record (Bob)
        Person updatedPerson = {"Bobby", 26};

        // Update the second record (index 1)
        updatePersonRecord(file, 1, updatedPerson);

        // --- Verify the Updates ---
        file.seekg(0, ios::beg);  // Move to the beginning of the file to read all records

        Person person;
        cout << "\nReading the updated data from the file:\n";
        while (file.read(reinterpret_cast<char*>(&person), sizeof(person))) {
            displayPerson(person);
        }

        file.close();
    }

    return 0;
}

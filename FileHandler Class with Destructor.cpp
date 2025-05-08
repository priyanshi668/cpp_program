#include <iostream>
#include <fstream>
using namespace std;

class FileHandler {
private:
    fstream file;

public:
    // Constructor to open a file
    FileHandler(const string &filename, ios::openmode mode) {
        file.open(filename, mode);  // Open the file with the specified mode
        if (!file.is_open()) {
            cout << "Error opening file!" << endl;
        } else {
            cout << "File opened successfully." << endl;
        }
    }

    // Method to write data to the file
    void writeToFile(const string &data) {
        if (file.is_open()) {
            file << data << endl;
            cout << "Data written to file." << endl;
        }
    }

    // Method to read data from the file
    void readFromFile() {
        string line;
        if (file.is_open()) {
            cout << "File content:" << endl;
            while (getline(file, line)) {
                cout << line << endl;
            }
        }
    }

    // Destructor to close the file
    ~FileHandler() {
        if (file.is_open()) {
            file.close();
            cout << "File closed successfully." << endl;
        }
    }
};

int main() {
    // Create an object of FileHandler that opens a file for writing
    FileHandler fh("example.txt", ios::out);

    // Write data to the file
    fh.writeToFile("Hello, World!");
    
    // Create another FileHandler object for reading the file
    FileHandler fh2("example.txt", ios::in);
    
    // Read the content of the file
    fh2.readFromFile();

    return 0;
}

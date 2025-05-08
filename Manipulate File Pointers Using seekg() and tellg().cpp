#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    const char* filename = "example.txt";
    
    // Create and write to the file
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error: Could not open the file for writing." << endl;
        return 1;
    }

    outFile << "This is a test file." << endl;
    outFile << "We are using seekg and tellg functions." << endl;
    outFile.close();

    // --- Reading from the file and manipulating file pointers ---
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error: Could not open the file for reading." << endl;
        return 1;
    }

    // Display current position of file pointer (should be at the beginning initially)
    cout << "Initial file pointer position: " << inFile.tellg() << endl;

    // Read the first line
    string line;
    getline(inFile, line);
    cout << "First line read: " << line << endl;

    // Display file pointer position after reading the first line
    cout << "File pointer after reading first line: " << inFile.tellg() << endl;

    // Move file pointer to the beginning of the file
    inFile.seekg(0, ios::beg);
    cout << "File pointer after seekg to the beginning: " << inFile.tellg() << endl;

    // Read the first line again
    getline(inFile, line);
    cout << "First line read again: " << line << endl;

    // Move file pointer to the end of the file
    inFile.seekg(0, ios::end);
    cout << "File pointer after seekg to the end: " << inFile.tellg() << endl;

    inFile.close();
    
    return 0;
}

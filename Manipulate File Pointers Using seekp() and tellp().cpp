#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    const char* filename = "output.txt";

    // Create and write to the file
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error: Could not open the file for writing." << endl;
        return 1;
    }

    outFile << "This is the first line." << endl;
    outFile << "This is the second line." << endl;

    // Display the initial position of the put pointer (after writing the second line)
    cout << "Initial put pointer position: " << outFile.tellp() << endl;

    // Move the put pointer to the beginning of the file
    outFile.seekp(0, ios::beg);
    cout << "Put pointer after seekp to the beginning: " << outFile.tellp() << endl;

    // Write new data after moving the pointer
    outFile << "This is a new first line." << endl;

    // Move the put pointer to the end of the file
    outFile.seekp(0, ios::end);
    cout << "Put pointer after seekp to the end: " << outFile.tellp() << endl;

    // Close the file
    outFile.close();

    // Reopen the file to check the contents
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error: Could not open the file for reading." << endl;
        return 1;
    }

    string line;
    cout << "\nContents of the file:\n";
    while (getline(inFile, line)) {
        cout << line << endl;
    }

    inFile.close();
    return 0;
}

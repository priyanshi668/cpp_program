#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    const char* filename = "sample.txt";

    // --- Creating and Opening a File ---
    ofstream outFile(filename);  // Creates and opens the file for writing

    if (!outFile) {
        cerr << "Error: Could not create or open the file." << endl;
        return 1;
    }

    // Write some data to the file
    outFile << "This is a sample file created using file streams." << endl;
    outFile << "File creation and writing is successful!" << endl;

    // Close the file after writing
    outFile.close();
    cout << "File created and data written successfully." << endl;

    // --- Opening and Reading the File ---
    ifstream inFile(filename);  // Opens the file for reading

    if (!inFile) {
        cerr << "Error: Could not open the file for reading." << endl;
        return 1;
    }

    string line;
    cout << "\nContents of the file are:\n";
    while (getline(inFile, line)) {
        cout << line << endl;
    }

    // Close the file after reading
    inFile.close();
    cout << "\nFile read successfully." << endl;

    return 0;
}

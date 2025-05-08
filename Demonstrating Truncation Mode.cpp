#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    const char* filename = "example_truncation.txt";

    // --- Writing initial data to the file ---
    {
        ofstream outFile(filename, ios::out);  // Open the file for writing (creating a new file or overwriting it)
        if (!outFile) {
            cerr << "Error: Could not open the file for initial writing." << endl;
            return 1;
        }

        outFile << "Initial content of the file.\n";
        outFile << "This is some important data.\n";
        outFile.close();
        cout << "Initial content written to the file.\n";
    }

    // --- Opening file in truncation mode and writing new data ---
    {
        ofstream outFile(filename, ios::out | ios::trunc);  // Open the file in truncation mode
        if (!outFile) {
            cerr << "Error: Could not open the file in truncation mode." << endl;
            return 1;
        }

        // Writing new data to the file after truncation
        outFile << "This data is written after truncating the file.\n";
        outFile << "Previous content has been erased.\n";
        outFile.close();
        cout << "\nFile contents have been truncated, and new data has been written.\n";
    }

    // --- Reading the file to verify truncation ---
    {
        ifstream inFile(filename, ios::in);  // Open the file for reading
        if (!inFile) {
            cerr << "Error: Could not open the file for reading." << endl;
            return 1;
        }

        cout << "\nReading the file after truncation:\n";
        string line;
        while (getline(inFile, line)) {
            cout << line << endl;  // Output the contents of the file
        }
        inFile.close();
    }

    return 0;
}

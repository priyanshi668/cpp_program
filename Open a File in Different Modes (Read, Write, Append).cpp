#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    const char* filename = "example.txt";

    // --- Writing to the file in write mode ---
    {
        ofstream outFile(filename, ios::out);  // Open file for writing
        if (!outFile) {
            cerr << "Error: Could not open file for writing." << endl;
            return 1;
        }

        outFile << "This is the first line of text." << endl;
        outFile << "This is the second line of text." << endl;
        outFile.close();
        cout << "File written successfully in write mode (ios::out).\n";
    }

    // --- Reading from the file in read mode ---
    {
        ifstream inFile(filename, ios::in);  // Open file for reading
        if (!inFile) {
            cerr << "Error: Could not open file for reading." << endl;
            return 1;
        }

        string line;
        cout << "\nReading file in read mode (ios::in):\n";
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    }

    // --- Appending to the file in append mode ---
    {
        ofstream outFile(filename, ios::app);  // Open file for appending
        if (!outFile) {
            cerr << "Error: Could not open file for appending." << endl;
            return 1;
        }

        outFile << "This is the appended third line of text." << endl;
        outFile.close();
        cout << "\nFile appended successfully in append mode (ios::app).\n";
    }

    // --- Reading from the file after appending ---
    {
        ifstream inFile(filename, ios::in);  // Open file for reading again
        if (!inFile) {
            cerr << "Error: Could not open file for reading after appending." << endl;
            return 1;
        }

        string line;
        cout << "\nReading file after appending (ios::in):\n";
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    }

    return 0;
}

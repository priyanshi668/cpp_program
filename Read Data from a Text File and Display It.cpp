#include <iostream>
#include <fstream>  // For file operations
#include <string>

using namespace std;

int main() {
    ifstream inputFile("data.txt"); // Open file for reading
    string line;

    // Check if the file opened successfully
    if (!inputFile) {
        cerr << "Error: Could not open the file." << endl;
        return 1;
    }

    cout << "Contents of the file:\n";

    // Read line by line from the file
    while (getline(inputFile, line)) {
        cout << line << endl;
    }

    inputFile.close(); // Close the file

    return 0;
}

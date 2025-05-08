#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    fstream file("example.txt", ios::in | ios::out | ios::app); // Open file for input & output with append mode

    // Check if the file opened successfully
    if (!file) {
        cerr << "Error: Could not open the file." << endl;
        return 1;
    }

    string input;
    cout << "Enter a line to append to the file: ";
    getline(cin, input);

    // Write to the file
    file << input << endl;

    // Move file pointer to beginning for reading
    file.seekg(0);

    cout << "\nCurrent contents of the file:\n";

    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();

    return 0;
}

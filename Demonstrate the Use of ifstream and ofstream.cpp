#include <iostream>   // For cin, cout
#include <fstream>    // For ifstream, ofstream
#include <string>     // For string

using namespace std;

int main() {
    // Create and open an output file stream (ofstream)
    ofstream outFile("example.txt");

    // Check if the file was opened successfully
    if (!outFile) {
        cerr << "Error opening file for writing!" << endl;
        return 1;  // Exit if file cannot be opened
    }

    // Write data to the file
    outFile << "Name: John Doe\n";
    outFile << "Age: 30\n";
    outFile << "Salary: 55000.50\n";

    // Close the output file stream
    outFile.close();

    // Create and open an input file stream (ifstream)
    ifstream inFile("example.txt");

    // Check if the file was opened successfully
    if (!inFile) {
        cerr << "Error opening file for reading!" << endl;
        return 1;  // Exit if file cannot be opened
    }

    string line;
    
    // Read data from the file and display it
    cout << "\nReading from the file:\n";
    while (getline(inFile, line)) {
        cout << line << endl;  // Output the contents of the file
    }

    // Close the input file stream
    inFile.close();

    return 0;
}

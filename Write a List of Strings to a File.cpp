#include <iostream>   // For cin, cout
#include <fstream>    // For ofstream
#include <vector>     // For vector
#include <string>     // For string

using namespace std;

int main() {
    // List of strings to write to the file
    vector<string> strings = {
        "Hello, World!",
        "This is a test.",
        "Writing strings to a file.",
        "C++ file handling is fun!",
        "End of the list."
    };

    // Create an output file stream (ofstream) to write to a file
    ofstream outFile("strings.txt");

    // Check if the file was opened successfully
    if (!outFile) {
        cerr << "Error opening file for writing!" << endl;
        return 1;  // Exit if file cannot be opened
    }

    // Write each string to the file
    for (const string& str : strings) {
        outFile << str << endl;  // Write string followed by a newline
    }

    // Close the output file stream
    outFile.close();

    cout << "Strings have been written to the file 'strings.txt'." << endl;

    return 0;
}

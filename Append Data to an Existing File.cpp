#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream outFile("append_example.txt", ios::app);  // Open in append mode
    string input;

    // Check if file is opened successfully
    if (!outFile) {
        cerr << "Error: Could not open the file for appending." << endl;
        return 1;
    }

    cout << "Enter text to append to the file (type 'exit' to finish):" << endl;

    // Get input and append to file until user types 'exit'
    while (true) {
        getline(cin, input);
        if (input == "exit")
            break;

        outFile << input << endl;
    }

    outFile.close();
    cout << "Data successfully appended to append_example.txt" << endl;

    return 0;
}

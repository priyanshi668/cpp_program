#include <iostream>
#include <fstream>  // For file stream
#include <string>

using namespace std;

int main() {
    ofstream outputFile("output.txt");  // Open file for writing
    string userInput;

    // Check if the file opened successfully
    if (!outputFile) {
        cerr << "Error: Could not open the file for writing." << endl;
        return 1;
    }

    cout << "Enter text to write to the file (type 'exit' to finish):" << endl;

    // Read multiple lines from the user and write to the file
    while (true) {
        getline(cin, userInput);

        if (userInput == "exit") {
            break;
        }

        outputFile << userInput << endl;
    }

    outputFile.close();  // Close the file
    cout << "Data written to output.txt successfully." << endl;

    return 0;
}

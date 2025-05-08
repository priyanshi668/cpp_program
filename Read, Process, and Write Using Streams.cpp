#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

// Function to convert a string to uppercase
string toUpperCase(const string& input) {
    string result = input;
    for (char& ch : result) {
        ch = toupper(ch);
    }
    return result;
}

int main() {
    string userInput;
    string processedData;
    const string filename = "output.txt";

    // Step 1: Read user input
    cout << "Enter a line of text: ";
    getline(cin, userInput);

    // Step 2: Process the input (convert to uppercase)
    processedData = toUpperCase(userInput);

    // Step 3: Write the processed data to a file
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error: Unable to open file for writing." << endl;
        return 1;
    }

    outFile << "Original Input: " << userInput << endl;
    outFile << "Processed Output: " << processedData << endl;

    outFile.close();
    cout << "Processed data has been written to " << filename << endl;

    return 0;
}

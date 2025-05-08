#include <iostream>
#include <fstream>

using namespace std;

int main() {
    const char* filenameText = "example_text.txt";
    const char* filenameBinary = "example_binary.dat";

    // --- Writing in Text Mode ---
    {
        ofstream outFileText(filenameText, ios::out);  // Open file for writing in text mode
        if (!outFileText) {
            cerr << "Error: Could not open the file for writing (Text mode)." << endl;
            return 1;
        }

        // Writing data with a newline character in text mode
        outFileText << "Hello, world!" << endl;
        outFileText << "This is a test." << endl;
        outFileText.close();
        cout << "Data written to file in text mode." << endl;
    }

    // --- Writing in Binary Mode ---
    {
        ofstream outFileBinary(filenameBinary, ios::out | ios::binary);  // Open file for writing in binary mode
        if (!outFileBinary) {
            cerr << "Error: Could not open the file for writing (Binary mode)." << endl;
            return 1;
        }

        // Writing data in binary mode (including newline characters as they are)
        const char* data = "Hello, world!\nThis is a test.\n";
        outFileBinary.write(data, strlen(data));
        outFileBinary.close();
        cout << "Data written to file in binary mode." << endl;
    }

    // --- Reading from Text Mode File ---
    {
        ifstream inFileText(filenameText, ios::in);  // Open file for reading in text mode
        if (!inFileText) {
            cerr << "Error: Could not open the file for reading (Text mode)." << endl;
            return 1;
        }

        cout << "\nReading from text file:\n";
        string line;
        while (getline(inFileText, line)) {
            cout << line << endl;  // Output text file content
        }
        inFileText.close();
    }

    // --- Reading from Binary Mode File ---
    {
        ifstream inFileBinary(filenameBinary, ios::in | ios::binary);  // Open file for reading in binary mode
        if (!inFileBinary) {
            cerr << "Error: Could not open the file for reading (Binary mode)." << endl;
            return 1;
        }

        cout << "\nReading from binary file:\n";
        char ch;
        while (inFileBinary.get(ch)) {
            cout << ch;  // Output binary file content as raw characters
        }
        inFileBinary.close();
    }

    return 0;
}

#include <iostream>  // For cin, cout
#include <fstream>   // For file handling (optional)
#include <string>    // For string manipulation

using namespace std;

int main() {
    // Demonstrating unformatted input using get()
    char ch;

    // Read one character at a time from standard input (cin) using get()
    cout << "Enter some characters (press Enter to stop):\n";
    while (cin.get(ch)) {  // get() reads one character at a time
        if (ch == '\n') {
            break;  // Stop reading when Enter key is pressed (newline character)
        }
        cout.put(ch);  // Output the character using put()
    }

    cout << "\n\n";

    // Demonstrating unformatted output using put()
    cout << "Now, let's demonstrate writing characters to the console using put().\n";
    cout.put('A');  // Put a single character 'A'
    cout.put('B');  // Put another character 'B'
    cout.put('\n'); // Insert a newline character

    // Example of writing to a file (optional)
    ofstream outFile("unformatted_output.txt");

    // Check if the file was opened successfully
    if (outFile) {
        outFile.put('C');  // Writing 'C' to the file using put()
        outFile.put('D');  // Writing 'D' to the file using put()
        outFile.put('\n'); // Writing a newline to the file
    } else {
        cerr << "Error opening file for writing!" << endl;
        return 1;
    }

    // Close the file
    outFile.close();

    cout << "\nThe characters 'A' and 'B' were output to the console.\n";
    cout << "The characters 'C' and 'D' were written to the file 'unformatted_output.txt'.\n";

    return 0;
}

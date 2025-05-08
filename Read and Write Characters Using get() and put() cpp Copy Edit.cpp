#include <iostream>  // For cin, cout
#include <fstream>   // For file handling (optional)

using namespace std;

int main() {
    char ch;

    // Demonstrate unformatted input using get()
    cout << "Enter characters (press Enter to stop):\n";
    
    // Read characters until the newline (Enter) is pressed
    while (cin.get(ch)) {  // get() reads one character at a time
        if (ch == '\n') {
            break;  // Stop reading when Enter key is pressed
        }
        // Output the character to the console using put()
        cout.put(ch);  // put() outputs the character to the console
    }

    cout << "\n\n";

    // Demonstrate writing characters to the console using put()
    cout << "Now, writing characters to the console using put():\n";
    cout.put('X');  // Writing 'X' to the console using put()
    cout.put('Y');  // Writing 'Y' to the console using put()
    cout.put('\n'); // Writing a newline to the console using put()

    // Optional: Writing characters to a file using put()
    ofstream outFile("characters_output.txt");

    // Check if the file was opened successfully
    if (outFile) {
        outFile.put('A');  // Writing 'A' to the file using put()
        outFile.put('B');  // Writing 'B' to the file using put()
        outFile.put('\n'); // Writing a newline to the file
    } else {
        cerr << "Error opening file for writing!" << endl;
        return 1;  // Exit if file cannot be opened
    }

    // Close the output file stream
    outFile.close();

    cout << "\nThe characters 'A' and 'B' were written to the file 'characters_output.txt'.\n";

    return 0;
}

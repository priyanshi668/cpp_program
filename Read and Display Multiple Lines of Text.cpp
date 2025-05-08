#include <iostream>  // For cin, cout
#include <string>    // For string and getline

using namespace std;

int main() {
    string line;
    int numLines;

    // Ask the user for how many lines they want to input
    cout << "How many lines of text would you like to enter? ";
    cin >> numLines;
    cin.ignore();  // Ignore the newline character left in the input buffer

    // Read multiple lines of text
    cout << "\nEnter " << numLines << " lines of text:\n";
    for (int i = 1; i <= numLines; ++i) {
        cout << "Line " << i << ": ";
        getline(cin, line);  // Read an entire line of text
        cout << "You entered: " << line << endl;
    }

    return 0;
}

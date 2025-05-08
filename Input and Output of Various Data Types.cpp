#include <iostream>  // For cin, cout
#include <string>    // For string

using namespace std;

int main() {
    // Declare variables for different data types
    int integer;
    float floatNum;
    double doubleNum;
    char character;
    string str;

    // Input and output for int
    cout << "Enter an integer: ";
    cin >> integer;
    cout << "You entered the integer: " << integer << endl;

    // Input and output for float
    cout << "Enter a float: ";
    cin >> floatNum;
    cout << "You entered the float: " << floatNum << endl;

    // Input and output for double
    cout << "Enter a double: ";
    cin >> doubleNum;
    cout << "You entered the double: " << doubleNum << endl;

    // Input and output for char
    cout << "Enter a character: ";
    cin >> character;
    cout << "You entered the character: " << character << endl;

    // Input and output for string
    cout << "Enter a string: ";
    cin.ignore();  // To ignore the leftover newline character in the input buffer
    getline(cin, str);  // Read a whole line as a string
    cout << "You entered the string: " << str << endl;

    return 0;
}

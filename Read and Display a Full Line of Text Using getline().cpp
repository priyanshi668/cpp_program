#include <iostream>  // For cin, cout
#include <string>    // For string manipulation

using namespace std;

int main() {
    string inputLine;

    // Prompt the user to enter a line of text
    cout << "Enter a line of text: ";

    // Use getline to read a full line of text, including spaces
    getline(cin, inputLine);

    // Display the entered line
    cout << "You entered: " << inputLine << endl;

    return 0;
}

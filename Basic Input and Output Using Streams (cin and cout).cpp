#include <iostream>  // For cin, cout

using namespace std;

int main() {
    // Declare variables
    string name;
    int age;
    double height;

    // Prompt user for input
    cout << "Enter your name: ";
    cin >> name;  // Read user input for name

    cout << "Enter your age: ";
    cin >> age;   // Read user input for age

    cout << "Enter your height (in meters): ";
    cin >> height;  // Read user input for height

    // Output the collected information
    cout << "\nHello, " << name << "!" << endl;
    cout << "Your age is: " << age << " years." << endl;
    cout << "Your height is: " << height << " meters." << endl;

    return 0;
}

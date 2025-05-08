#include <iostream>  // For cin, cout
#include <iomanip>   // For setprecision, fixed, scientific

using namespace std;

int main() {
    double number = 123.456789;

    // Default display without any formatting
    cout << "Default formatting:\n";
    cout << number << endl;

    // Display with a precision of 3 digits
    cout << "\nWith setprecision(3):\n";
    cout << fixed << setprecision(3) << number << endl;

    // Display with a precision of 5 digits
    cout << "\nWith setprecision(5):\n";
    cout << fixed << setprecision(5) << number << endl;

    // Display with a precision of 8 digits
    cout << "\nWith setprecision(8):\n";
    cout << fixed << setprecision(8) << number << endl;

    // Display with scientific notation and a precision of 3 digits
    cout << "\nWith scientific notation and setprecision(3):\n";
    cout << scientific << setprecision(3) << number << endl;

    // Display with scientific notation and a precision of 6 digits
    cout << "\nWith scientific notation and setprecision(6):\n";
    cout << scientific << setprecision(6) << number << endl;

    return 0;
}

#include <iostream>    // For cin, cout
#include <iomanip>     // For setw, setprecision, fixed

using namespace std;

int main() {
    // Variables for demonstration
    int integer = 123;
    double floatingPoint = 123.456789;

    // Using setw to set the width of the output
    cout << "Using setw to set the width of the output:" << endl;
    cout << "Integer with width 10: " << setw(10) << integer << endl;
    cout << "Floating-point with width 15: " << setw(15) << floatingPoint << endl;

    // Using setprecision to set the number of digits to display for floating-point numbers
    cout << "\nUsing setprecision to set the precision of the floating-point number:" << endl;
    cout << "Floating-point with precision 4: " << setprecision(4) << floatingPoint << endl;
    cout << "Floating-point with precision 8: " << setprecision(8) << floatingPoint << endl;

    // Using fixed and setprecision to format floating-point numbers to a fixed number of decimal places
    cout << "\nUsing fixed and setprecision to format the floating-point number:" << endl;
    cout << "Floating-point with fixed format and precision 2: " << fixed << setprecision(2) << floatingPoint << endl;
    cout << "Floating-point with fixed format and precision 4: " << fixed << setprecision(4) << floatingPoint << endl;

    return 0;
}

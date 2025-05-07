#include <iostream>
#include <cmath>  // For power function (optional if using custom logic)
using namespace std;

// Function to calculate power with a default exponent of 2
double power(double base, int exponent = 2) {
    return pow(base, exponent);  // Using the built-in power function
    // Alternatively, you could use a custom calculation:
    // double result = 1;
    // for (int i = 1; i <= exponent; i++) {
    //     result *= base;
    // }
    // return result;
}

int main() {
    double base;
    int exponent;

    // Input base number
    cout << "Enter base number: ";
    cin >> base;

    // Calculate power with default exponent (2)
    double result = power(base);
    cout << "Result with default exponent 2: " << result << endl;

    // Input exponent for custom power
    cout << "Enter exponent: ";
    cin >> exponent;

    // Calculate power with user-defined exponent
    result = power(base, exponent);
    cout << "Result with exponent " << exponent << ": " << result << endl;

    return 0;
}

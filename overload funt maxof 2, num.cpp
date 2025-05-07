#include <iostream>
using namespace std;

// Overloaded function to find maximum of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Overloaded function to find maximum of three numbers
int max(int a, int b, int c) {
    return max(max(a, b), c);  // Reuse the two-argument max function
}

int main() {
    int num1, num2, num3;

    // Input for two numbers
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    cout << "Maximum of " << num1 << " and " << num2 << " is: " << max(num1, num2) << endl;

    // Input for three numbers
    cout << "Enter three numbers: ";
    cin >> num1 >> num2 >> num3;
    cout << "Maximum of " << num1 << ", " << num2 << ", and " << num3 << " is: " << max(num1, num2, num3) << endl;

    return 0;
}

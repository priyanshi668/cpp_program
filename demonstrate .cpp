#include <iostream>
using namespace std;

// Recursive function to calculate factorial of a number
int factorial(int n) {
    if (n == 0 || n == 1)  // Base case: factorial of 0 or 1 is 1
        return 1;
    else
        return n * factorial(n - 1);  // Recursive call
}

int main() {
    int number;

    // Input number
    cout << "Enter a number: ";
    cin >> number;

    // Calculate and display factorial
    cout << "Factorial of " << number << " is: " << factorial(number) << endl;

    return 0;
}

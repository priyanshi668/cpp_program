#include <iostream>
using namespace std;

// Function prototype
int multiply(int a, int b);

int main() {
    int num1, num2;

    // Input two integers
    cout << "Enter two integers: ";
    cin >> num1 >> num2;

    // Call the function to calculate the product
    int product = multiply(num1, num2);
    cout << "The product of " << num1 << " and " << num2 << " is: " << product << endl;

    return 0;
}

// Function definition
int multiply(int a, int b) {
    return a * b; // Return the product of a and b
}

#include <iostream>
using namespace std;

// Function prototypes for arithmetic operations
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (b != 0) 
        return a / b;
    else {
        cout << "Error: Division by zero!" << endl;
        return 0;  // Returning 0 to indicate error
    }
}

int main() {
    // Array of function pointers
    int (*operations[4])(int, int) = {add, subtract, multiply, divide};

    int num1, num2, choice;

    // Input two numbers
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    // Display the menu
    cout << "Choose an operation: \n";
    cout << "0. Add\n";
    cout << "1. Subtract\n";
    cout << "2. Multiply\n";
    cout << "3. Divide\n";
    cout << "Enter your choice (0-3): ";
    cin >> choice;

    // Call the selected operation using function pointer
    if (choice >= 0 && choice <= 3) {
        int result = operations[choice](num1, num2);  // Calling the selected function
        cout << "Result: " << result << endl;
    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}

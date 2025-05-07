#include <iostream>
#include <stack>
using namespace std;

int main() {
    int decimal, remainder;
    stack<int> binary;

    // Input the decimal number
    cout << "Enter a decimal number: ";
    cin >> decimal;

    // Convert the decimal number to binary
    while (decimal > 0) {
        remainder = decimal % 2;  // Get the remainder (either 0 or 1)
        binary.push(remainder);    // Push the remainder onto the stack
        decimal = decimal / 2;     // Divide the decimal number by 2
    }

    // Output the binary number
    cout << "Binary equivalent: ";
    while (!binary.empty()) {
        cout << binary.top();  // Print the top of the stack (most significant bit)
        binary.pop();          // Pop the top element from the stack
    }

    cout << endl;

    return 0;
}

#include <iostream>
using namespace std;

int main() {
    int number, originalNumber, reversedNumber = 0, remainder;

    cout << "Enter an integer: ";
    cin >> number;

    originalNumber = number;  // Store the original number

    // Make sure the number is positive
    number = abs(number); 

    // Reverse the number
    while (number != 0) {
        remainder = number % 10;  // Get the last digit
        reversedNumber = reversedNumber * 10 + remainder;  // Build the reversed number
        number /= 10;  // Remove the last digit
    }

    // Check if the original number is the same as the reversed number
    if (originalNumber == reversedNumber) {
        cout << originalNumber << " is a palindrome." << endl;
    } else {
        cout << originalNumber << " is not a palindrome." << endl;
    }

    return 0;
}

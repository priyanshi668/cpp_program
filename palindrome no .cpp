#include <iostream>
using namespace std;

int main() {
    int number, originalNumber, reversed = 0, remainder;

    cout << "Enter an integer: ";
    cin >> number;

    originalNumber = number;  // Save the original number

    // Reverse the number using a while loop
    while (number != 0) {
        remainder = number % 10;
        reversed = reversed * 10 + remainder;
        number /= 10;
    }

    // Check if the original and reversed numbers are the same
    if (originalNumber == reversed)
        cout << originalNumber << " is a palindrome." << endl;
    else
        cout << originalNumber << " is not a palindrome." << endl;

    return 0;
}

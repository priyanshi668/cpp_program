#include <iostream>
using namespace std;

int main() {
    int number, reversed = 0;

    cout << "Enter an integer: ";
    cin >> number;

    int original = number; // Store original number for display

    while (number != 0) {
        int digit = number % 10;          // Get the last digit
        reversed = reversed * 10 + digit; // Append digit to reversed number
        number /= 10;                     // Remove the last digit
    }

    cout << "Reversed number of " << original << " is: " << reversed << endl;

    return 0;
}

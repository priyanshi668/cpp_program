#include <iostream>
#include <cmath> // For pow function
using namespace std;

int main() {
    int number, originalNumber, remainder, result = 0, digits = 0;

    cout << "Enter an integer: ";
    cin >> number;

    originalNumber = number;

    // Count the number of digits
    int temp = number;
    while (temp != 0) {
        temp /= 10;
        ++digits;
    }

    // Calculate the sum of digits raised to the power of 'digits'
    temp = number;
    while (temp != 0) {
        remainder = temp % 10;
        result += pow(remainder, digits);
        temp /= 10;
    }

    if (result == originalNumber)
        cout << originalNumber << " is an Armstrong number." << endl;
    else
        cout << originalNumber << " is not an Armstrong number." << endl;

    return 0;
}

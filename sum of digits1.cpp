#include <iostream>
using namespace std;

int main() {
    int number, sum = 0;

    cout << "Enter an integer: ";
    cin >> number;

    number = abs(number); // Handle negative numbers

    while (number != 0) {
        sum += number % 10;  // Add the last digit to sum
        number /= 10;        // Remove the last digit
    }

    cout << "The sum of the digits is: " << sum << endl;

    return 0;
}

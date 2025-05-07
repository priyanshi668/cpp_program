#include <iostream>
using namespace std;

int main() {
    int number, count = 0;

    cout << "Enter an integer: ";
    cin >> number;

    // Handle zero explicitly
    if (number == 0) {
        count = 1;
    } else {
        // Make number positive if it's negative
        if (number < 0) number = -number;

        while (number != 0) {
            number /= 10;  // Remove the last digit
            count++;       // Increment digit count
        }
    }

    cout << "Number of digits: " << count << endl;

    return 0;
}

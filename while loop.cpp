#include <iostream>
using namespace std;

int main() {
    int i = 1;          // Start from the first natural number
    int sum = 0;        // Variable to store the sum

    while (i <= 50) {
        sum += i;       // Add the current number to sum
        i++;            // Move to the next number
    }

    cout << "The sum of the first 50 natural numbers is: " << sum << endl;
    return 0;
}

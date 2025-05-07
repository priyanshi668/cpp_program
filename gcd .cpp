#include <iostream>
using namespace std;

int main() {
    int num1, num2;

    cout << "Enter two integers: ";
    cin >> num1 >> num2;

    // Ensure that num1 is always the greater number
    if (num1 < num2) {
        swap(num1, num2);
    }

    // Using Euclidean algorithm to find GCD
    while (num2 != 0) {
        int remainder = num1 % num2;
        num1 = num2;
        num2 = remainder;
    }

    cout << "The GCD is: " << num1 << endl;

    return 0;
}

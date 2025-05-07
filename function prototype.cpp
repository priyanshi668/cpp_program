#include <iostream>
using namespace std;

// Function prototype
int findMax(int a, int b, int c);

int main() {
    int num1, num2, num3;

    // Input three numbers from the user
    cout << "Enter three numbers: ";
    cin >> num1 >> num2 >> num3;

    // Call the findMax function and output the result
    int max = findMax(num1, num2, num3);
    cout << "The maximum number is: " << max << endl;

    return 0;
}

// Function definition
int findMax(int a, int b, int c) {
    if (a >= b && a >= c) {
        return a;
    } else if (b >= a && b >= c) {
        return b;
    } else {
        return c;
    }
}

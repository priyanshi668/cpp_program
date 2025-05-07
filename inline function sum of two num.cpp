#include <iostream>
using namespace std;

// Inline function to calculate sum
inline int sum(int a, int b) {
    return a + b;
}

int main() {
    int num1, num2;

    // Input two numbers
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    // Call inline function
    int result = sum(num1, num2);

    cout << "The sum of " << num1 << " and " << num2 << " is: " << result << endl;

    return 0;
}

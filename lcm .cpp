#include <iostream>
using namespace std;

int main() {
    int num1, num2, lcm;

    // Input two numbers
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    // Find the larger of the two numbers
    int max_num = (num1 > num2) ? num1 : num2;

    // Find the LCM using a while loop
    lcm = max_num;  // Start with the maximum of num1 and num2

    while (true) {
        if (lcm % num1 == 0 && lcm % num2 == 0) {
            break;  // If lcm is divisible by both num1 and num2, it's the LCM
        }
        lcm += max_num;  // Increase lcm by the larger number until condition is met
    }

    cout << "The LCM of " << num1 << " and " << num2 << " is: " << lcm << endl;

    return 0;
}

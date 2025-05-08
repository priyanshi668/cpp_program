#include <iostream>  // For cin, cout

using namespace std;

int main() {
    int sum = 0;    // To store the sum of integers
    int num;        // To store each input number
    char choice;    // To handle the decision of whether to continue or not

    cout << "Enter integers to sum. Type 'q' to quit.\n";
    
    while (true) {
        cout << "Enter an integer: ";
        if (cin >> num) {  // If input is an integer
            sum += num;    // Add the number to sum
        } else {  // If input is not an integer (non-numeric input)
            cout << "You entered a non-integer. Exiting...\n";
            break;  // Exit the loop
        }
    }

    // Output the sum
    cout << "The sum of the integers is: " << sum << endl;

    return 0;
}

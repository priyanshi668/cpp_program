#include <iostream>
using namespace std;

// Function to swap values using pointers
void swapValues(int* a, int* b) {
    int temp = *a;  // Store the value of *a in a temporary variable
    *a = *b;        // Assign the value of *b to *a
    *b = temp;      // Assign the value of temp (original *a) to *b
}

int main() {
    int num1, num2;

    // Input two integers
    cout << "Enter the value for num1: ";
    cin >> num1;
    cout << "Enter the value for num2: ";
    cin >> num2;

    // Display values before swapping
    cout << "\nBefore swapping: " << endl;
    cout << "num1 = " << num1 << ", num2 = " << num2 << endl;

    // Call the swap function with the addresses of num1 and num2
    swapValues(&num1, &num2);

    // Display values after swapping
    cout << "\nAfter swapping: " << endl;
    cout << "num1 = " << num1 << ", num2 = " << num2 << endl;

    return 0;
}

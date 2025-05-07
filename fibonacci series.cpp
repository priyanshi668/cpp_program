#include <iostream>
using namespace std;

int main() {
    int n;

    // Input the number of terms
    cout << "Enter the number of terms: ";
    cin >> n;

    // First two terms of the Fibonacci series
    int a = 0, b = 1;

    // Print the Fibonacci series
    cout << "Fibonacci series up to " << n << " terms: ";
    for (int i = 1; i <= n; ++i) {
        cout << a << " "; // Print current term
        int nextTerm = a + b; // Calculate next term
        a = b; // Update a to the previous term
        b = nextTerm; // Update b to the next term
    }

    cout << endl;

    return 0;
}

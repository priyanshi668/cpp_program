#include <iostream>
using namespace std;

int main() {
    int rows = 3;  // Number of rows for the pyramid

    // Outer loop for each row
    for (int i = 1; i <= rows; ++i) {
        // Print spaces before the stars in each row
        for (int j = i; j < rows; ++j) {
            cout << " ";
        }

        // Print stars in each row
        for (int k = 1; k <= (2 * i - 1); ++k) {
            cout << "*";
            if (k < (2 * i - 1)) cout << " ";  // Add space between stars
        }

        cout << endl;  // Move to the next line
    }

    return 0;
}

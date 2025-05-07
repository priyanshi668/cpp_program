#include <iostream>
using namespace std;

int main() {
    for (int i = 1; i <= 100; ++i) {
        if (i % 3 == 0 && i % 5 == 0) {
            cout << "FizzBuzz" << endl;  // Multiples of both 3 and 5
        } else if (i % 3 == 0) {
            cout << "Fizz" << endl;      // Multiples of 3 only
        } else if (i % 5 == 0) {
            cout << "Buzz" << endl;      // Multiples of 5 only
        } else {
            cout << i << endl;           // All other numbers
        }
    }

    return 0;
}

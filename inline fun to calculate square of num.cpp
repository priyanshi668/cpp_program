#include <iostream>
using namespace std;

// Inline function to calculate square
inline int square(int x) {
    return x * x;
}

int main() {
    int num;

    cout << "Enter a number: ";
    cin >> num;

    cout << "The square of " << num << " is: " << square(num) << endl;

    return 0;
}

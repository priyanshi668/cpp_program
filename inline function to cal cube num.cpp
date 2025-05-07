#include <iostream>
using namespace std;

// Inline function to calculate cube
inline int cube(int x) {
    return x * x * x;
}

int main() {
    int num;

    cout << "Enter a number: ";
    cin >> num;

    cout << "The cube of " << num << " is: " << cube(num) << endl;

    return 0;
}

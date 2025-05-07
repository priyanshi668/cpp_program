#include <iostream>
using namespace std;

// Function prototype
void swap(int &a, int &b);

int main() {
    int x = 10, y = 20;

    cout << "Before swap: x = " << x << ", y = " << y << endl;

    // Call the swap function
    swap(x, y);

    cout << "After swap:  x = " << x << ", y = " << y << endl;

    return 0;
}

// Function definition
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

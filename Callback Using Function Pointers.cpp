#include <iostream>
using namespace std;

// Define a function type: takes an int, returns void
typedef void (*Callback)(int);

// Function that accepts a callback
void processData(int data, Callback cb) {
    cout << "Processing data: " << data << endl;

    // Simulate processing, then call the callback
    cb(data); // Callback invoked
}

// Callback functions
void printDouble(int x) {
    cout << "Double of data: " << x * 2 << endl;
}

void printSquare(int x) {
    cout << "Square of data: " << x * x << endl;
}

int main() {
    int value;
    cout << "Enter a number: ";
    cin >> value;

    cout << "\nUsing printDouble as callback:\n";
    processData(value, printDouble);

    cout << "\nUsing printSquare as callback:\n";
    processData(value, printSquare);

    return 0;
}

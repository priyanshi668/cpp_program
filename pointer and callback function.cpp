#include <iostream>
using namespace std;

// Function that will be used as a callback
void printSquare(int x) {
    cout << "Square of " << x << " is: " << x * x << endl;
}

void printCube(int x) {
    cout << "Cube of " << x << " is: " << x * x * x << endl;
}

// Function that takes a callback function as a parameter
void applyFunction(int x, void (*func)(int)) {
    func(x);  // Calls the function passed as a pointer
}

int main() {
    int num;

    cout << "Enter a number: ";
    cin >> num;

    // Passing the printSquare function as a callback
    applyFunction(num, printSquare);

    // Passing the printCube function as a callback
    applyFunction(num, printCube);

    return 0;
}

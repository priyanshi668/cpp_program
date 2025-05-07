#include <iostream>
using namespace std;

// Macro to calculate square
#define SQUARE_MACRO(x) ((x) * (x))

// Inline function to calculate square
inline int squareInline(int x) {
    return x * x;
}

int main() {
    int num;

    cout << "Enter a number: ";
    cin >> num;

    // Using macro
    int macroResult = SQUARE_MACRO(num);

    // Using inline function
    int inlineResult = squareInline(num);

    cout << "Using macro: " << macroResult << endl;
    cout << "Using inline function: " << inlineResult << endl;

    return 0;
}

#include <iostream>
using namespace std;

// Macro to find maximum
#define MAX_MACRO(a, b) ((a) > (b) ? (a) : (b))

// Inline function to find maximum
inline int maxInline(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int x, y;

    cout << "Enter two numbers: ";
    cin >> x >> y;

    // Using macro
    int macroMax = MAX_MACRO(x, y);

    // Using inline function
    int inlineMax = maxInline(x, y);

    cout << "Maximum using macro: " << macroMax << endl;
    cout << "Maximum using inline function: " << inlineMax << endl;

    return 0;
}

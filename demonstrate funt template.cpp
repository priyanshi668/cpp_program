#include <iostream>
using namespace std;

// Function template to find the maximum of two values
template <typename T>
T maximum(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    int x = 10, y = 20;
    float a = 3.5f, b = 2.1f;
    double p = 15.7, q = 10.3;

    // Call function template for int
    cout << "Maximum of " << x << " and " << y << " is: " << maximum(x, y) << endl;

    // Call function template for float
    cout << "Maximum of " << a << " and " << b << " is: " << maximum(a, b) << endl;

    // Call function template for double
    cout << "Maximum of " << p << " and " << q << " is: " << maximum(p, q) << endl;

    return 0;
}

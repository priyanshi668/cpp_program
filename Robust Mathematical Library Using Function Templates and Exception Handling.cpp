#include <iostream>
#include <cmath>
#include <stdexcept>
#include <type_traits>

using namespace std;

// Exception classes
class DivisionByZeroException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Division by zero!";
    }
};

class NegativeSqrtException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Square root of a negative number!";
    }
};

// Function template for division with exception handling
template <typename T>
T safeDivide(T a, T b) {
    if (b == 0) {
        throw DivisionByZeroException();  // Throw an exception if dividing by zero
    }
    return a / b;
}

// Function template for square root with exception handling
template <typename T>
T safeSqrt(T a) {
    if (a < 0) {
        throw NegativeSqrtException();  // Throw an exception if taking the square root of a negative number
    }
    return sqrt(a);
}

// Function template for addition
template <typename T>
T add(T a, T b) {
    return a + b;
}

// Function template for subtraction
template <typename T>
T subtract(T a, T b) {
    return a - b;
}

// Function template for multiplication
template <typename T>
T multiply(T a, T b) {
    return a * b;
}

// Main function to test the mathematical library
int main() {
    try {
        // Test safe division
        cout << "10 / 2 = " << safeDivide(10, 2) << endl;
        cout << "10 / 0 = " << safeDivide(10, 0) << endl;  // This will throw an exception

    } catch (const DivisionByZeroException& e) {
        cout << e.what() << endl;
    }

    try {
        // Test safe square root
        cout << "sqrt(25) = " << safeSqrt(25.0) << endl;
        cout << "sqrt(-25) = " << safeSqrt(-25.0) << endl;  // This will throw an exception

    } catch (const NegativeSqrtException& e) {
        cout << e.what() << endl;
    }

    try {
        // Test basic operations
        cout << "5 + 3 = " << add(5, 3) << endl;
        cout << "5 - 3 = " << subtract(5, 3) << endl;
        cout << "5 * 3 = " << multiply(5, 3) << endl;

    } catch (const std::exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}

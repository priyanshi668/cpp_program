#include <iostream>
using namespace std;

class Math {
public:
    // Static method for addition
    static double add(double a, double b) {
        return a + b;
    }

    // Static method for subtraction
    static double subtract(double a, double b) {
        return a - b;
    }

    // Static method for multiplication
    static double multiply(double a, double b) {
        return a * b;
    }

    // Static method for division
    static double divide(double a, double b) {
        if (b != 0)
            return a / b;
        else {
            cout << "Error: Division by zero!" << endl;
            return 0;
        }
    }
};

int main() {
    // Using static methods without creating an object
    cout << "Addition: " << Math::add(10, 5) << endl;
    cout << "Subtraction: " << Math::subtract(10, 5) << endl;
    cout << "Multiplication: " << Math::multiply(10, 5) << endl;
    cout << "Division: " << Math::divide(10, 5) << endl;

    return 0;
}

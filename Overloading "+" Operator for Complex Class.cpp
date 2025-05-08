#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    // Constructor to initialize real and imaginary parts
    Complex(double r = 0, double i = 0) {
        real = r;
        imag = i;
    }

    // Overloading the "+" operator to add two complex numbers
    Complex operator+(const Complex &other) {
        Complex temp;
        temp.real = real + other.real;   // Add real parts
        temp.imag = imag + other.imag;   // Add imaginary parts
        return temp;
    }

    // Method to display a complex number
    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    // Creating two complex numbers
    Complex c1(3.5, 4.5);
    Complex c2(1.5, 2.5);

    // Adding two complex numbers using overloaded "+" operator
    Complex c3 = c1 + c2;

    // Displaying the result
    cout << "Result of addition: ";
    c3.display();

    return 0;
}

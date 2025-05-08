#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

public:
    // Constructor to initialize fraction
    Fraction(int num = 0, int denom = 1) {
        numerator = num;
        denominator = denom;
    }

    // Overloading the ">>" operator for input
    friend ostream& operator<<(ostream &out, const Fraction &f) {
        out << f.numerator << "/" << f.denominator;
        return out;
    }

    // Overloading the "<<" operator for output
    friend istream& operator>>(istream &in, Fraction &f) {
        cout << "Enter numerator: ";
        in >> f.numerator;
        cout << "Enter denominator: ";
        in >> f.denominator;
        return in;
    }
};

int main() {
    Fraction f1, f2;
    
    // Taking input using overloaded ">>" operator
    cin >> f1;
    cin >> f2;

    // Displaying output using overloaded "<<" operator
    cout << "Fraction 1: " << f1 << endl;
    cout << "Fraction 2: " << f2 << endl;

    return 0;
}

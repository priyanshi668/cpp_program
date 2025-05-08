#include <iostream>
#include <vector>
using namespace std;

class Polynomial {
private:
    vector<int> coefficients; // Vector to store the coefficients of the polynomial

public:
    // Constructor to initialize polynomial with a given set of coefficients
    Polynomial(const vector<int>& coef) : coefficients(coef) {}

    // Function to add two polynomials
    Polynomial add(const Polynomial& other) {
        // Find the larger degree
        int maxSize = max(coefficients.size(), other.coefficients.size());
        vector<int> result(maxSize, 0);

        // Add coefficients from the first polynomial
        for (int i = 0; i < coefficients.size(); ++i) {
            result[i] += coefficients[i];
        }

        // Add coefficients from the second polynomial
        for (int i = 0; i < other.coefficients.size(); ++i) {
            result[i] += other.coefficients[i];
        }

        return Polynomial(result);
    }

    // Function to multiply two polynomials
    Polynomial multiply(const Polynomial& other) {
        int resultSize = coefficients.size() + other.coefficients.size() - 1;
        vector<int> result(resultSize, 0);

        // Multiply the polynomials
        for (int i = 0; i < coefficients.size(); ++i) {
            for (int j = 0; j < other.coefficients.size(); ++j) {
                result[i + j] += coefficients[i] * other.coefficients[j];
            }
        }

        return Polynomial(result);
    }

    // Function to display the polynomial
    void display() const {
        int degree = coefficients.size();
        for (int i = degree - 1; i >= 0; --i) {
            if (coefficients[i] != 0) {
                if (i != degree - 1) {
                    cout << (coefficients[i] > 0 ? " + " : " - ");
                }
                cout << abs(coefficients[i]);
                if (i > 0) {
                    cout << "x";
                    if (i > 1) {
                        cout << "^" << i;
                    }
                }
            }
        }
        cout << endl;
    }
};

int main() {
    // Define two polynomials: 3x^2 + 2x + 1 and x^2 + 4x + 5
    Polynomial poly1({1, 2, 3});  // 3x^2 + 2x + 1
    Polynomial poly2({5, 4, 1});  // x^2 + 4x + 5

    // Display the polynomials
    cout << "Polynomial 1: ";
    poly1.display();
    cout << "Polynomial 2: ";
    poly2.display();

    // Add the polynomials
    Polynomial resultAdd = poly1.add(poly2);
    cout << "Sum of Polynomials: ";
    resultAdd.display();

    // Multiply the polynomials
    Polynomial resultMul = poly1.multiply(poly2);
    cout << "Product of Polynomials: ";
    resultMul.display();

    return 0;
}

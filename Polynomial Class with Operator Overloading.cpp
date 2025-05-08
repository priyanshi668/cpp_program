#include <iostream>
#include <vector>
using namespace std;

class Polynomial {
private:
    vector<int> coeffs; // coeffs[i] represents the coefficient of x^i

public:
    // Constructor with degree
    Polynomial(int degree = 0) {
        coeffs.resize(degree + 1, 0);
    }

    // Set coefficient for x^i
    void setCoefficient(int degree, int coeff) {
        if (degree >= coeffs.size())
            coeffs.resize(degree + 1, 0);
        coeffs[degree] = coeff;
    }

    // Display the polynomial
    void display() const {
        bool isFirst = true;
        for (int i = coeffs.size() - 1; i >= 0; --i) {
            if (coeffs[i] != 0) {
                if (!isFirst) cout << " + ";
                cout << coeffs[i] << "x^" << i;
                isFirst = false;
            }
        }
        if (isFirst) cout << "0";
        cout << endl;
    }

    // Operator overloading for addition
    Polynomial operator+(const Polynomial& rhs) const {
        int maxDegree = max(coeffs.size(), rhs.coeffs.size());
        Polynomial result(maxDegree - 1);

        for (int i = 0; i < maxDegree; ++i) {
            int a = (i < coeffs.size()) ? coeffs[i] : 0;
            int b = (i < rhs.coeffs.size()) ? rhs.coeffs[i] : 0;
            result.setCoefficient(i, a + b);
        }
        return result;
    }

    // Operator overloading for multiplication
    Polynomial operator*(const Polynomial& rhs) const {
        int degreeA = coeffs.size() - 1;
        int degreeB = rhs.coeffs.size() - 1;
        Polynomial result(degreeA + degreeB);

        for (int i = 0; i <= degreeA; ++i) {
            for (int j = 0; j <= degreeB; ++j) {
                int existing = result.coeffs[i + j];
                result.setCoefficient(i + j, existing + coeffs[i] * rhs.coeffs[j]);
            }
        }
        return result;
    }
};

// Main function to demonstrate polynomial operations
int main() {
    Polynomial p1, p2;

    // p1 = 2x^2 + 3x + 1
    p1.setCoefficient(2, 2);
    p1.setCoefficient(1, 3);
    p1.setCoefficient(0, 1);

    // p2 = x^2 + 4x + 5
    p2.setCoefficient(2, 1);
    p2.setCoefficient(1, 4);
    p2.setCoefficient(0, 5);

    cout << "Polynomial 1: ";
    p1.display();

    cout << "Polynomial 2: ";
    p2.display();

    Polynomial sum = p1 + p2;
    Polynomial product = p1 * p2;

    cout << "\nSum: ";
    sum.display();

    cout << "Product: ";
    product.display();

    return 0;
}

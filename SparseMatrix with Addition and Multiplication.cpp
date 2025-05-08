#include <iostream>
#include <vector>
using namespace std;

struct Element {
    int row, col, value;
};

class SparseMatrix {
private:
    int rows, cols;
    vector<Element> elements;

public:
    // Constructor
    SparseMatrix(int r, int c) : rows(r), cols(c) {}

    // Add a non-zero element
    void addElement(int r, int c, int val) {
        if (val != 0)
            elements.push_back({r, c, val});
    }

    // Display sparse matrix as full matrix
    void display() const {
        int k = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (k < elements.size() && elements[k].row == i && elements[k].col == j) {
                    cout << elements[k].value << " ";
                    k++;
                } else {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }

    // Addition of two sparse matrices
    SparseMatrix add(const SparseMatrix& other) {
        SparseMatrix result(rows, cols);
        int i = 0, j = 0;

        while (i < elements.size() && j < other.elements.size()) {
            if (elements[i].row == other.elements[j].row && elements[i].col == other.elements[j].col) {
                int sum = elements[i].value + other.elements[j].value;
                if (sum != 0)
                    result.addElement(elements[i].row, elements[i].col, sum);
                i++; j++;
            } else if ((elements[i].row < other.elements[j].row) ||
                       (elements[i].row == other.elements[j].row && elements[i].col < other.elements[j].col)) {
                result.addElement(elements[i].row, elements[i].col, elements[i].value);
                i++;
            } else {
                result.addElement(other.elements[j].row, other.elements[j].col, other.elements[j].value);
                j++;
            }
        }

        while (i < elements.size()) {
            result.addElement(elements[i].row, elements[i].col, elements[i].value);
            i++;
        }

        while (j < other.elements.size()) {
            result.addElement(other.elements[j].row, other.elements[j].col, other.elements[j].value);
            j++;
        }

        return result;
    }

    // Multiplication of two sparse matrices
    SparseMatrix multiply(const SparseMatrix& other) {
        if (cols != other.rows) {
            cout << "Matrix multiplication not possible!" << endl;
            return SparseMatrix(0, 0);
        }

        SparseMatrix result(rows, other.cols);

        for (auto& a : elements) {
            for (auto& b : other.elements) {
                if (a.col == b.row) {
                    int r = a.row;
                    int c = b.col;
                    int val = a.value * b.value;

                    // Search if element already exists at (r, c)
                    bool found = false;
                    for (auto& e : result.elements) {
                        if (e.row == r && e.col == c) {
                            e.value += val;
                            found = true;
                            break;
                        }
                    }

                    if (!found)
                        result.addElement(r, c, val);
                }
            }
        }

        return result;
    }
};

int main() {
    SparseMatrix A(3, 3);
    A.addElement(0, 0, 2);
    A.addElement(1, 1, 3);
    A.addElement(2, 2, 4);

    SparseMatrix B(3, 3);
    B.addElement(0, 1, 5);
    B.addElement(1, 0, 6);
    B.addElement(2, 2, 1);

    cout << "Matrix A:" << endl;
    A.display();
    cout << "\nMatrix B:" << endl;
    B.display();

    SparseMatrix sum = A.add(B);
    cout << "\nA + B:" << endl;
    sum.display();

    SparseMatrix product = A.multiply(B);
    cout << "\nA * B:" << endl;
    product.display();

    return 0;
}

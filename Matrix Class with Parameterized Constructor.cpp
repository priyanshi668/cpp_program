#include <iostream>
using namespace std;

class Matrix {
private:
    int rows, cols;
    int** matrix;

public:
    // Parameterized constructor to initialize 2D array
    Matrix(int r, int c) {
        rows = r;
        cols = c;

        // Dynamically allocate memory for the 2D array
        matrix = new int*[rows];
        for (int i = 0; i < rows; i++) {
            matrix[i] = new int[cols];
        }
    }

    // Method to set matrix values
    void setValues() {
        cout << "Enter elements of the matrix:" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << "Element at [" << i << "][" << j << "]: ";
                cin >> matrix[i][j];
            }
        }
    }

    // Method to display matrix values
    void display() {
        cout << "Matrix:" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Destructor to release dynamically allocated memory
    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
};

int main() {
    // Create a 2x3 matrix
    Matrix mat(2, 3);

    // Set matrix values
    mat.setValues();

    // Display matrix
    mat.display();

    return 0;
}

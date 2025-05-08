#include <iostream>
#include <vector>
using namespace std;

// Function template to add two matrices
template <typename T>
vector<vector<T>> addMatrices(const vector<vector<T>>& A, const vector<vector<T>>& B) {
    int rows = A.size();
    int cols = A[0].size();
    vector<vector<T>> result(rows, vector<T>(cols));

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result[i][j] = A[i][j] + B[i][j];

    return result;
}

// Function template to multiply two matrices
template <typename T>
vector<vector<T>> multiplyMatrices(const vector<vector<T>>& A, const vector<vector<T>>& B) {
    int rowsA = A.size();
    int colsA = A[0].size();
    int colsB = B[0].size();

    vector<vector<T>> result(rowsA, vector<T>(colsB, 0));

    for (int i = 0; i < rowsA; ++i)
        for (int j = 0; j < colsB; ++j)
            for (int k = 0; k < colsA; ++k)
                result[i][j] += A[i][k] * B[k][j];

    return result;
}

// Utility function to display a matrix
template <typename T>
void displayMatrix(const vector<vector<T>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& elem : row)
            cout << elem << " ";
        cout << endl;
    }
}

// Main function to demonstrate functionality
int main() {
    vector<vector<int>> mat1 = {
        {1, 2},
        {3, 4}
    };

    vector<vector<int>> mat2 = {
        {5, 6},
        {7, 8}
    };

    cout << "Matrix 1:\n";
    displayMatrix(mat1);

    cout << "\nMatrix 2:\n";
    displayMatrix(mat2);

    cout << "\nMatrix Addition:\n";
    vector<vector<int>> sum = addMatrices(mat1, mat2);
    displayMatrix(sum);

    cout << "\nMatrix Multiplication:\n";
    vector<vector<int>> product = multiplyMatrices(mat1, mat2);
    displayMatrix(product);

    return 0;
}

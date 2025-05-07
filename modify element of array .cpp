#include <iostream>
using namespace std;

// Function prototype
void doubleElements(int arr[], int size);

int main() {
    const int size = 5;
    int numbers[size] = {1, 2, 3, 4, 5};

    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    // Call function to double each element
    doubleElements(numbers, size);

    cout << "Modified array: ";
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    return 0;
}

// Function definition
void doubleElements(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] *= 2; // Double each element
    }
}

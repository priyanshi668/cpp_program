#include <iostream>
using namespace std;

int main() {
    int size;

    // Ask the user for the size of the array
    cout << "Enter the size of the array: ";
    cin >> size;

    // Dynamically allocate memory for the array using 'new'
    int* arr = new int[size];

    // Initialize the array using pointers
    for (int i = 0; i < size; i++) {
        *(arr + i) = i + 1;  // Assigning values: 1, 2, 3, ..., size
    }

    // Display the array elements
    cout << "Array elements are:" << endl;
    for (int i = 0; i < size; i++) {
        cout << *(arr + i) << " ";  // Accessing values using pointers
    }
    cout << endl;

    // Deallocate the memory using 'delete'
    delete[] arr;

    return 0;
}

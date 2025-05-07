#include <iostream>
using namespace std;

// Function prototype
void printArray(int arr[], int size);

int main() {
    const int size = 5;
    int numbers[size] = {10, 20, 30, 40, 50};

    // Call the function to print the array
    cout << "The elements of the array are: ";
    printArray(numbers, size);

    return 0;
}

// Function definition
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

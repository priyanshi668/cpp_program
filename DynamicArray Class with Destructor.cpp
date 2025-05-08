#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* arr;  // Pointer to dynamically allocated array
    int size;

public:
    // Constructor to initialize the dynamic array with a given size
    DynamicArray(int s) {
        size = s;
        arr = new int[size];  // Dynamically allocate memory for the array
        cout << "Array of size " << size << " created." << endl;
    }

    // Method to set values in the array
    void setValues() {
        for (int i = 0; i < size; i++) {
            cout << "Enter element " << i + 1 << ": ";
            cin >> arr[i];
        }
    }

    // Method to display the values in the array
    void display() {
        cout << "Array contents: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Destructor to deallocate dynamically allocated memory
    ~DynamicArray() {
        delete[] arr;  // Deallocate memory
        cout << "Array memory deallocated." << endl;
    }
};

int main() {
    // Create a DynamicArray object with a size of 5
    DynamicArray dynArr(5);

    // Set values in the array
    dynArr.setValues();

    // Display the array
    dynArr.display();

    // Destructor is automatically called when dynArr goes out of scope
    return 0;
}

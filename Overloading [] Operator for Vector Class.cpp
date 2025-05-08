#include <iostream>
using namespace std;

class Vector {
private:
    int* arr;  // Pointer to array
    int size;

public:
    // Constructor to initialize the vector with given size
    Vector(int s) {
        size = s;
        arr = new int[size];  // Dynamically allocate memory for the array
    }

    // Overloading the "[]" operator to access elements of the vector
    int& operator[](int index) {
        if (index >= 0 && index < size) {
            return arr[index];  // Return reference to the element
        } else {
            cout << "Index out of bounds!" << endl;
            exit(1);  // Exit program if index is out of bounds
        }
    }

    // Method to display the vector elements
    void display() const {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Destructor to free dynamically allocated memory
    ~Vector() {
        delete[] arr;
    }
};

int main() {
    // Create a vector of size 5
    Vector v(5);

    // Using the overloaded "[]" operator to set values
    for (int i = 0; i < 5; i++) {
        v[i] = (i + 1) * 10;  // Assign values to vector elements
    }

    // Display the vector elements
    cout << "Vector elements: ";
    v.display();

    // Access elements using overloaded "[]" operator
    cout << "Element at index 2: " << v[2] << endl;

    return 0;
}

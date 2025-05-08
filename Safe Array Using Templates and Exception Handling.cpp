#include <iostream>
#include <stdexcept>
using namespace std;

// Template SafeArray class
template <typename T>
class SafeArray {
private:
    T* arr;
    int size;

public:
    // Constructor
    SafeArray(int size) {
        if (size <= 0)
            throw invalid_argument("Array size must be positive.");
        this->size = size;
        arr = new T[size];
    }

    // Overloaded [] operator with bounds checking
    T& operator[](int index) {
        if (index < 0 || index >= size)
            throw out_of_range("Index out of bounds.");
        return arr[index];
    }

    // Display function
    void display() const {
        cout << "Array contents: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Destructor
    ~SafeArray() {
        delete[] arr;
    }
};

// Main function to demonstrate SafeArray usage
int main() {
    try {
        int n;
        cout << "Enter size of integer array: ";
        cin >> n;

        SafeArray<int> intArray(n);

        cout << "Enter " << n << " integer elements:\n";
        for (int i = 0; i < n; i++) {
            cout << "Element [" << i << "]: ";
            cin >> intArray[i];
        }

        intArray.display();

        cout << "\nTrying to access an element out of bounds...\n";
        cout << intArray[n]; // Will throw an exception

    } catch (const invalid_argument& e) {
        cerr << "Invalid argument: " << e.what() << endl;
    } catch (const out_of_range& e) {
        cerr << "Out of range error: " << e.what() << endl;
    } catch (...) {
        cerr << "An unexpected error occurred.\n";
    }

    return 0;
}

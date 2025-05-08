#include <iostream>
using namespace std;

int main() {
    // Create an array of integers
    int arr[] = {10, 20, 30, 40, 50};
    
    // Pointer to the first element of the array
    int* ptr = arr;
    
    // Display the array elements using pointer arithmetic
    cout << "Array elements accessed using pointer arithmetic:" << endl;
    
    // Accessing the elements using pointer arithmetic
    for (int i = 0; i < 5; i++) {
        cout << "Element " << i + 1 << ": " << *(ptr + i) << endl;
    }
    
    // Displaying the elements using pointer increment (pointer arithmetic)
    cout << "\nUsing pointer increment to display the array elements:" << endl;
    
    for (int i = 0; i < 5; i++) {
        cout << "Element " << i + 1 << ": " << *ptr << endl;
        ptr++;  // Move the pointer to the next element
    }

    return 0;
}

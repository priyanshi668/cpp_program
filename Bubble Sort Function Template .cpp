#include <iostream>
using namespace std;

// Function template to perform bubble sort
template <typename T>
void bubbleSort(T arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to display array elements
template <typename T>
void displayArray(T arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Main function
int main() {
    // Integer array
    int intArr[] = {64, 25, 12, 22, 11};
    int intSize = sizeof(intArr) / sizeof(intArr[0]);

    cout << "Original integer array: ";
    displayArray(intArr, intSize);

    bubbleSort(intArr, intSize);

    cout << "Sorted integer array: ";
    displayArray(intArr, intSize);

    // Double array
    double doubleArr[] = {64.5, 25.1, 12.8, 22.2, 11.3};
    int doubleSize = sizeof(doubleArr) / sizeof(doubleArr[0]);

    cout << "Original double array: ";
    displayArray(doubleArr, doubleSize);

    bubbleSort(doubleArr, doubleSize);

    cout << "Sorted double array: ";
    displayArray(doubleArr, doubleSize);

    // String array (Bubble Sort works lexicographically on strings)
    string strArr[] = {"apple", "orange", "banana", "grape", "cherry"};
    int strSize = sizeof(strArr) / sizeof(strArr[0]);

    cout << "Original string array: ";
    displayArray(strArr, strSize);

    bubbleSort(strArr, strSize);

    cout << "Sorted string array: ";
    displayArray(strArr, strSize);

    return 0;
}

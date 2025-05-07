#include <iostream>
using namespace std;

int main() {
    int n;

    // Input the number of elements in the array
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];

    // Input array elements
    cout << "Enter " << n << " elements: " << endl;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Duplicate elements in the array are: ";
    bool foundDuplicate = false;

    // Nested loops to find duplicates
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] == arr[j]) { // If duplicate is found
                cout << arr[i] << " ";
                foundDuplicate = true;
                break; // Avoid printing duplicates multiple times
            }
        }
    }

    if (!foundDuplicate) {
        cout << "No duplicates found.";
    }

    cout << endl;

    return 0;
}

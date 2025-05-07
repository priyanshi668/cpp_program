#include <iostream>
using namespace std;

int main() {
    int n;
    double sum = 0.0, average;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];

    cout << "Enter " << n << " integers:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        sum += arr[i];  // Add each element to the sum
    }

    if (n > 0) {
        average = sum / n;  // Calculate average
        cout << "The average of the array elements is: " << average << endl;
    } else {
        cout << "The array is empty, no average can be calculated." << endl;
    }

    return 0;
}

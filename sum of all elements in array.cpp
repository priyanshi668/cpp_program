#include <iostream>
using namespace std;

int main() {
    int n, sum = 0;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];

    cout << "Enter " << n << " integers:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        sum += arr[i]; // Add each element to the sum
    }

    cout << "The sum of all elements in the array is: " << sum << endl;

    return 0;
}

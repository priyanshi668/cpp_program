#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter the number of terms for the Fibonacci series: ";
    cin >> n;

    int first = 0, second = 1, next;

    cout << "Fibonacci Series: ";

    for (int i = 1; i <= n; ++i) {
        cout << first << " ";

        next = first + second;
        first = second;
        second = next;
    }

    cout << endl;
    return 0;
}

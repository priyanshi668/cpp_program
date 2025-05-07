#include <iostream>
using namespace std;

int main() {
    int n;
    double harmonicSum = 0.0;

    // Input the number of terms
    cout << "Enter the number of terms: ";
    cin >> n;

    // Calculate the sum of the harmonic series
    for (int i = 1; i <= n; ++i) {
        harmonicSum += 1.0 / i;
    }

    // Output the result
    cout << "The sum of the harmonic series up to " << n << " terms is: " << harmonicSum << endl;

    return 0;
}

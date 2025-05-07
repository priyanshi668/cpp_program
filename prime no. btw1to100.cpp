#include <iostream>
using namespace std;

int main() {
    int num, i, j, isPrime;

    cout << "Prime numbers between 1 and 100 are:" << endl;

    for (num = 2; num <= 100; ++num) {
        isPrime = 1; // Assume the number is prime

        // Check if num is divisible by any number from 2 to num-1
        for (i = 2; i <= num / 2; ++i) {
            if (num % i == 0) {
                isPrime = 0; // num is not prime
                break;
            }
        }

        // If isPrime remains 1, num is prime
        if (isPrime == 1) {
            cout << num << " ";
        }
    }

    cout << endl;
    return 0;
}

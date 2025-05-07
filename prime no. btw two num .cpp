#include <iostream>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; ++i) { // Check divisibility up to the square root of num
        if (num % i == 0) {
            return false; // If divisible by any number other than 1 and itself, it's not prime
        }
    }
    return true; // If not divisible by any number, it's prime
}

int main() {
    int start, end;

    cout << "Enter the range (start and end): ";
    cin >> start >> end;

    cout << "Prime numbers between " << start << " and " << end << " are: ";
    for (int num = start; num <= end; ++num) {
        if (isPrime(num)) {
            cout << num << " ";
        }
    }

    cout << endl;

    return 0;
}

#include <iostream>
using namespace std;

int main() {
    int sum = 0;

    for (int i = 2; i <= 100; i += 2) { // Start from 2 and increment by 2
        sum += i;
    }

    cout << "The sum of all even numbers between 1 and 100 is: " << sum << endl;

    return 0;
}

#include <iostream>ile 
using namespace std;

int main() {
    int number, i = 1;

    cout << "Enter a number to print its multiplication table: ";
    cin >> number;

    do {
        cout << number << " x " << i << " = " << number * i << endl;
        i++;
    } while (i <= 10);

    return 0;
}

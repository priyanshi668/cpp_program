#include <iostream>
#include <cmath>  // For power function
using namespace std;

int main() {
    string binary;
    int decimal = 0;

    cout << "Enter a binary number: ";
    cin >> binary;

    int length = binary.length();
    int i = 0;

    // Convert binary to decimal using while loop
    while (i < length) {
        if (binary[i] == '1') {
            decimal += pow(2, length - 1 - i);  // Add the corresponding power of 2
        }
        i++;
    }

    cout << "The decimal equivalent of binary " << binary << " is: " << decimal << endl;

    return 0;
}

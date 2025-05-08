#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class BigNumber {
private:
    string number; // Store the number as string

    // Helper function to remove leading zeros
    string removeLeadingZeros(string str) const {
        int i = 0;
        while (i < str.size() - 1 && str[i] == '0')
            i++;
        return str.substr(i);
    }

public:
    // Constructor
    BigNumber(string num = "0") {
        // Remove leading zeros
        number = removeLeadingZeros(num);
    }

    // Display
    void display() const {
        cout << number << endl;
    }

    // Addition
    BigNumber add(const BigNumber& other) const {
        string num1 = number;
        string num2 = other.number;
        string result = "";

        int carry = 0;
        int i = num1.size() - 1;
        int j = num2.size() - 1;

        while (i >= 0 || j >= 0 || carry) {
            int digit1 = (i >= 0) ? num1[i--] - '0' : 0;
            int digit2 = (j >= 0) ? num2[j--] - '0' : 0;
            int sum = digit1 + digit2 + carry;
            carry = sum / 10;
            result.push_back(sum % 10 + '0');
        }

        reverse(result.begin(), result.end());
        return BigNumber(result);
    }

    // Subtraction (Assumes *this >= other)
    BigNumber subtract(const BigNumber& other) const {
        string num1 = number;
        string num2 = other.number;
        string result = "";

        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int borrow = 0;

        while (i >= 0) {
            int digit1 = num1[i] - '0';
            int digit2 = (j >= 0) ? num2[j] - '0' : 0;
            digit1 -= borrow;

            if (digit1 < digit2) {
                digit1 += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }

            result.push_back((digit1 - digit2) + '0');
            i--; j--;
        }

        reverse(result.begin(), result.end());
        return BigNumber(removeLeadingZeros(result));
    }

    // Comparison (returns -1 if <, 0 if ==, 1 if >)
    int compare(const BigNumber& other) const {
        if (number.length() > other.number.length()) return 1;
        if (number.length() < other.number.length()) return -1;
        return number.compare(other.number);
    }

    // Getter for testing
    string getNumber() const {
        return number;
    }
};

// Example usage
int main() {
    BigNumber num1("987654321987654321987654321");
    BigNumber num2("123456789123456789123456789");

    cout << "Number 1: ";
    num1.display();

    cout << "Number 2: ";
    num2.display();

    BigNumber sum = num1.add(num2);
    cout << "\nSum: ";
    sum.display();

    BigNumber diff = num1.subtract(num2);
    cout << "Difference: ";
    diff.display();

    int cmp = num1.compare(num2);
    cout << "Comparison: ";
    if (cmp == 0) cout << "Equal\n";
    else if (cmp > 0) cout << "Number 1 is greater\n";
    else cout << "Number 2 is greater\n";

    return 0;
}

#include <iostream>
#include <string>
using namespace std;

// Overloaded function to print int
void print(int num) {
    cout << "Integer: " << num << endl;
}

// Overloaded function to print float
void print(float num) {
    cout << "Float: " << num << endl;
}

// Overloaded function to print string
void print(string str) {
    cout << "String: " << str << endl;
}

int main() {
    int a = 10;
    float b = 3.14;
    string c = "Hello, World!";

    // Calling overloaded functions
    print(a);
    print(b);
    print(c);

    return 0;
}

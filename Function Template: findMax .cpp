#include <iostream>
using namespace std;

// Template function to find the maximum of two values
template <typename T>
T findMax(T a, T b) {
    return (a > b) ? a : b;
}
int main() {
    cout << "Max of 10 and 20: " << findMax(10, 20) << endl;
    cout << "Max of 3.14 and 2.71: " << findMax(3.14, 2.71) << endl;
    cout << "Max of 'A' and 'Z': " << findMax('A', 'Z') << endl;
    cout << "Max of \"apple\" and \"banana\": " << findMax(string("apple"), string("banana")) << endl;

    return 0;
}

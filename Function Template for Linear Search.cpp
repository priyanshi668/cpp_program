#include <iostream>

// Function template for linear search
template <typename T>
int linearSearch(T arr[], int size, T key) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == key) {
            return i;  // Return index if found
        }
    }
    return -1;  // Return -1 if not found
}

// Test the function with different data types
int main() {
    int intArr[] = {10, 20, 30, 40, 50};
    char charArr[] = {'a', 'e', 'i', 'o', 'u'};
    std::string strArr[] = {"apple", "banana", "cherry"};

    int intIndex = linearSearch(intArr, 5, 30);
    int charIndex = linearSearch(charArr, 5, 'o');
    int strIndex = linearSearch(strArr, 3, std::string("banana"));

    std::cout << "Index of 30 in intArr: " << intIndex << std::endl;
    std::cout << "Index of 'o' in charArr: " << charIndex << std::endl;
    std::cout << "Index of \"banana\" in strArr: " << strIndex << std::endl;

    return 0;
}

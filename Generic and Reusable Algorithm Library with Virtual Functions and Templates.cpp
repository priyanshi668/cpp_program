#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <type_traits>

using namespace std;

// Base class for generic sorting algorithm
template <typename T>
class SortAlgorithm {
public:
    virtual void sort(vector<T>& data) const = 0;  // Pure virtual function for sorting
    virtual ~SortAlgorithm() = default;  // Virtual destructor
};

// Derived class for Bubble Sort
template <typename T>
class BubbleSort : public SortAlgorithm<T> {
public:
    void sort(vector<T>& data) const override {
        cout << "Performing Bubble Sort..." << endl;
        bool swapped;
        for (size_t i = 0; i < data.size() - 1; ++i) {
            swapped = false;
            for (size_t j = 0; j < data.size() - i - 1; ++j) {
                if (data[j] > data[j + 1]) {
                    swap(data[j], data[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped) break;  // If no elements were swapped, the array is sorted
        }
    }
};

// Derived class for Selection Sort
template <typename T>
class SelectionSort : public SortAlgorithm<T> {
public:
    void sort(vector<T>& data) const override {
        cout << "Performing Selection Sort..." << endl;
        for (size_t i = 0; i < data.size() - 1; ++i) {
            size_t minIndex = i;
            for (size_t j = i + 1; j < data.size(); ++j) {
                if (data[j] < data[minIndex]) {
                    minIndex = j;
                }
            }
            swap(data[i], data[minIndex]);
        }
    }
};

// Derived class for Insertion Sort
template <typename T>
class InsertionSort : public SortAlgorithm<T> {
public:
    void sort(vector<T>& data) const override {
        cout << "Performing Insertion Sort..." << endl;
        for (size_t i = 1; i < data.size(); ++i) {
            T key = data[i];
            size_t j = i;
            while (j > 0 && data[j - 1] > key) {
                data[j] = data[j - 1];
                --j;
            }
            data[j] = key;
        }
    }
};

// Generic function to print the elements of the container
template <typename T>
void printData(const vector<T>& data) {
    for (const T& item : data) {
        cout << item << " ";
    }
    cout << endl;
}

// Function to use the sorting algorithm
template <typename T>
void sortAndPrint(SortAlgorithm<T>* sorter, vector<T>& data) {
    sorter->sort(data);  // Call the sort method
    printData(data);  // Print the sorted data
}

int main() {
    vector<int> intData = {34, 7, 23, 32, 5, 62};
    vector<double> doubleData = {34.5, 23.1, 23.5, 5.5, 62.9};
    vector<string> stringData = {"apple", "orange", "banana", "kiwi", "grape"};

    // Sorting integer data using BubbleSort
    SortAlgorithm<int>* bubbleSortInt = new BubbleSort<int>();
    cout << "Sorting integer data using BubbleSort:" << endl;
    sortAndPrint(bubbleSortInt, intData);
    delete bubbleSortInt;

    // Sorting double data using SelectionSort
    SortAlgorithm<double>* selectionSortDouble = new SelectionSort<double>();
    cout << "\nSorting double data using SelectionSort:" << endl;
    sortAndPrint(selectionSortDouble, doubleData);
    delete selectionSortDouble;

    // Sorting string data using InsertionSort
    SortAlgorithm<string>* insertionSortString = new InsertionSort<string>();
    cout << "\nSorting string data using InsertionSort:" << endl;
    sortAndPrint(insertionSortString, stringData);
    delete insertionSortString;

    return 0;
}

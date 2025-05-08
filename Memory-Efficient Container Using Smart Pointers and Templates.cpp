#include <iostream>
#include <memory>
#include <vector>

using namespace std;

// Template class to implement a memory-efficient and type-safe container
template <typename T>
class SmartContainer {
private:
    vector<unique_ptr<T>> container;

public:
    // Function to add an element to the container
    void add(T* element) {
        container.push_back(make_unique<T>(*element)); // Adds a unique_ptr to the container
    }

    // Function to access an element at a specific index
    T& at(size_t index) {
        if (index >= container.size()) {
            throw out_of_range("Index out of bounds");
        }
        return *container.at(index);
    }

    // Function to display all elements in the container
    void display() const {
        for (const auto& item : container) {
            cout << *item << " ";
        }
        cout << endl;
    }

    // Function to get the size of the container
    size_t size() const {
        return container.size();
    }
};

// Main function to demonstrate the SmartContainer with smart pointers
int main() {
    try {
        // Create a container for integers
        SmartContainer<int> intContainer;

        // Add elements to the container
        intContainer.add(new int(10));
        intContainer.add(new int(20));
        intContainer.add(new int(30));

        // Display the elements
        cout << "Elements in the container: ";
        intContainer.display();

        // Access and print a specific element
        cout << "Element at index 1: " << intContainer.at(1) << endl;

        // Try accessing an out-of-bounds index
        // Uncomment the following line to test out-of-bounds access
        // cout << "Element at index 5: " << intContainer.at(5) << endl;

        cout << "Size of the container: " << intContainer.size() << endl;

    } catch (const exception& e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}

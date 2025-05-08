#include <iostream>
#include <vector>
#include <stdexcept>  // For exception handling

using namespace std;

// Abstract base class for collections
template <typename T>
class Collection {
public:
    virtual void add(const T& item) = 0;           // Add item to collection
    virtual void remove() = 0;                      // Remove item from collection
    virtual T& get() = 0;                           // Get the item from collection
    virtual bool isEmpty() const = 0;                // Check if collection is empty
    virtual void display() const = 0;                // Display all items in collection
    virtual ~Collection() = default;                 // Virtual destructor
};

// Derived class for List (vector-based collection)
template <typename T>
class List : public Collection<T> {
private:
    vector<T> data;

public:
    void add(const T& item) override {
        data.push_back(item);
    }

    void remove() override {
        if (isEmpty()) {
            throw runtime_error("Error: Cannot remove from an empty list.");
        }
        data.pop_back();
    }

    T& get() override {
        if (isEmpty()) {
            throw runtime_error("Error: Cannot get from an empty list.");
        }
        return data.back();
    }

    bool isEmpty() const override {
        return data.empty();
    }

    void display() const override {
        if (isEmpty()) {
            cout << "List is empty!" << endl;
        } else {
            cout << "List contents: ";
            for (const T& item : data) {
                cout << item << " ";
            }
            cout << endl;
        }
    }
};

// Derived class for Stack (LIFO collection)
template <typename T>
class Stack : public Collection<T> {
private:
    vector<T> data;

public:
    void add(const T& item) override {
        data.push_back(item);
    }

    void remove() override {
        if (isEmpty()) {
            throw runtime_error("Error: Cannot remove from an empty stack.");
        }
        data.pop_back();
    }

    T& get() override {
        if (isEmpty()) {
            throw runtime_error("Error: Cannot get from an empty stack.");
        }
        return data.back();
    }

    bool isEmpty() const override {
        return data.empty();
    }

    void display() const override {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
        } else {
            cout << "Stack contents (top to bottom): ";
            for (auto it = data.rbegin(); it != data.rend(); ++it) {
                cout << *it << " ";
            }
            cout << endl;
        }
    }
};

// Derived class for Queue (FIFO collection)
template <typename T>
class Queue : public Collection<T> {
private:
    vector<T> data;

public:
    void add(const T& item) override {
        data.push_back(item);
    }

    void remove() override {
        if (isEmpty()) {
            throw runtime_error("Error: Cannot remove from an empty queue.");
        }
        data.erase(data.begin());
    }

    T& get() override {
        if (isEmpty()) {
            throw runtime_error("Error: Cannot get from an empty queue.");
        }
        return data.front();
    }

    bool isEmpty() const override {
        return data.empty();
    }

    void display() const override {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
        } else {
            cout << "Queue contents (front to back): ";
            for (const T& item : data) {
                cout << item << " ";
            }
            cout << endl;
        }
    }
};

// Function template to demonstrate polymorphism and exception handling
template <typename T>
void demonstrateCollection(Collection<T>* collection) {
    try {
        collection->add(10);
        collection->add(20);
        collection->add(30);
        collection->display();

        collection->remove();
        collection->display();

        cout << "Front/Top element: " << collection->get() << endl;

        collection->remove();
        collection->remove();
        collection->remove();  // This will trigger an exception
    }
    catch (const exception& e) {
        cout << e.what() << endl;
    }
}

int main() {
    cout << "Demonstrating List (vector-based collection) with integers:" << endl;
    List<int> list;
    demonstrateCollection(&list);

    cout << "\nDemonstrating Stack (LIFO collection) with integers:" << endl;
    Stack<int> stack;
    demonstrateCollection(&stack);

    cout << "\nDemonstrating Queue (FIFO collection) with integers:" << endl;
    Queue<int> queue;
    demonstrateCollection(&queue);

    return 0;
}

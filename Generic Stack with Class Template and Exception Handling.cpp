#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Stack {
private:
    T* arr;
    int top;
    int capacity;

public:
    // Constructor
    Stack(int size = 100) {
        if (size <= 0)
            throw invalid_argument("Stack size must be positive.");
        arr = new T[size];
        capacity = size;
        top = -1;
    }

    // Push element onto stack
    void push(const T& element) {
        if (top >= capacity - 1)
            throw overflow_error("Stack Overflow: Cannot push onto full stack.");
        arr[++top] = element;
    }

    // Pop element from stack
    T pop() {
        if (top < 0)
            throw underflow_error("Stack Underflow: Cannot pop from empty stack.");
        return arr[top--];
    }

    // Peek at the top element
    T peek() const {
        if (top < 0)
            throw underflow_error("Stack is empty.");
        return arr[top];
    }

    // Check if stack is empty
    bool isEmpty() const {
        return top == -1;
    }

    // Destructor
    ~Stack() {
        delete[] arr;
    }
};

// Main function to demonstrate the Stack
int main() {
    try {
        Stack<int> intStack(5);

        cout << "Pushing 10, 20, 30 onto the stack...\n";
        intStack.push(10);
        intStack.push(20);
        intStack.push(30);

        cout << "Top element: " << intStack.peek() << endl;

        cout << "Popping: " << intStack.pop() << endl;
        cout << "Popping: " << intStack.pop() << endl;
        cout << "Popping: " << intStack.pop() << endl;

        cout << "Trying to pop from an empty stack...\n";
        intStack.pop(); // Should throw exception

    } catch (const exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }

    return 0;
}

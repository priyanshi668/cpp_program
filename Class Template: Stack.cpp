#include <iostream>
using namespace std;

const int MAX = 100;  // Maximum stack size

// Class template for Stack
template <typename T>
class Stack {
private:
    T arr[MAX];  // Array to store stack elements
    int top;     // Index of the top element

public:
    Stack() : top(-1) {}  // Constructor initializes top

    // Push an element onto the stack
    void push(T value) {
        if (top >= MAX - 1) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++top] = value;
    }

    // Pop an element from the stack
    void pop() {
        if (top < 0) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        cout << "Popped: " << arr[top--] << endl;
    }

    // Display all elements of the stack
    void display() {
        if (top < 0) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; --i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    Stack<int> intStack;
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);
    intStack.display();
    intStack.pop();
    intStack.display();

    cout << endl;

    Stack<string> stringStack;
    stringStack.push("Hello");
    stringStack.push("World");
    stringStack.display();
    stringStack.pop();
    stringStack.display();

    return 0;
}

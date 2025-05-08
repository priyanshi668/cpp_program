#include <iostream>
using namespace std;

// Queue class template
template <typename T>
class Queue {
private:
    T* arr;        // Dynamic array to hold queue elements
    int front;     // Index of the front element
    int rear;      // Index of the rear element
    int capacity;  // Maximum size of the queue
    int size;      // Current size of the queue

public:
    // Constructor to initialize queue with a given capacity
    Queue(int cap) : capacity(cap), front(0), rear(0), size(0) {
        arr = new T[capacity];
    }

    // Enqueue function to add an element to the queue
    void enqueue(T value) {
        if (size == capacity) {
            cout << "Queue Overflow!" << endl;
            return;
        }
        arr[rear] = value;
        rear = (rear + 1) % capacity;  // Circular increment
        size++;
    }

    // Dequeue function to remove the front element
    void dequeue() {
        if (size == 0) {
            cout << "Queue Underflow!" << endl;
            return;
        }
        cout << "Dequeued: " << arr[front] << endl;
        front = (front + 1) % capacity;  // Circular increment
        size--;
    }

    // Display all elements of the queue
    void display() {
        if (size == 0) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Queue elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[(front + i) % capacity] << " ";
        }
        cout << endl;
    }

    // Destructor to free allocated memory
    ~Queue() {
        delete[] arr;
    }
};
int main() {
    // Create a queue for integers with a capacity of 5
    Queue<int> intQueue(5);

    intQueue.enqueue(10);
    intQueue.enqueue(20);
    intQueue.enqueue(30);
    intQueue.enqueue(40);
    intQueue.enqueue(50);
    
    cout << "Integer Queue: ";
    intQueue.display();  // Output: 10 20 30 40 50

    intQueue.dequeue();  // Dequeues 10
    cout << "After dequeue: ";
    intQueue.display();  // Output: 20 30 40 50

    // Create a queue for strings with a capacity of 3
    Queue<string> strQueue(3);

    strQueue.enqueue("apple");
    strQueue.enqueue("banana");
    strQueue.enqueue("cherry");

    cout << "String Queue: ";
    strQueue.display();  // Output: apple banana cherry

    strQueue.dequeue();  // Dequeues "apple"
    cout << "After dequeue: ";
    strQueue.display();  // Output: banana cherry

    return 0;
}

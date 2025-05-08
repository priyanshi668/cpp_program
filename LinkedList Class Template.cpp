#include <iostream>
using namespace std;

// Node structure using template
template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) {}
};

// LinkedList class template
template <typename T>
class LinkedList {
private:
    Node<T>* head;

public:
    LinkedList() : head(nullptr) {}

    // Insert at the end
    void insert(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = newNode;
        } else {
            Node<T>* temp = head;
            while (temp->next)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    // Delete first occurrence of a value
    void remove(T value) {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        if (head->data == value) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            cout << "Deleted node with value: " << value << endl;
            return;
        }

        Node<T>* prev = head;
        Node<T>* curr = head->next;

        while (curr) {
            if (curr->data == value) {
                prev->next = curr->next;
                delete curr;
                cout << "Deleted node with value: " << value << endl;
                return;
            }
            prev = curr;
            curr = curr->next;
        }

        cout << "Value not found in list." << endl;
    }

    // Display the linked list
    void display() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node<T>* temp = head;
        cout << "LinkedList: ";
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Destructor to free memory
    ~LinkedList() {
        while (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Main function
int main() {
    // Integer LinkedList
    LinkedList<int> intList;
    intList.insert(10);
    intList.insert(20);
    intList.insert(30);
    intList.display();  // Output: 10 -> 20 -> 30 -> NULL

    intList.remove(20);
    intList.display();  // Output: 10 -> 30 -> NULL

    // String LinkedList
    LinkedList<string> strList;
    strList.insert("apple");
    strList.insert("banana");
    strList.insert("cherry");
    strList.display();  // Output: apple -> banana -> cherry -> NULL

    strList.remove("banana");
    strList.display();  // Output: apple -> cherry -> NULL

    return 0;
}

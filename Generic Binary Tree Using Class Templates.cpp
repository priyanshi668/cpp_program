#include <iostream>
using namespace std;

// Template class for a Binary Tree Node
template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    // Constructor
    BinaryTreeNode(T value) : data(value), left(nullptr), right(nullptr) {}
};

// Template class for the Binary Tree
template <typename T>
class BinaryTree {
private:
    BinaryTreeNode<T>* root;

    // Helper function to recursively delete the tree
    void deleteTree(BinaryTreeNode<T>* node) {
        if (node == nullptr) return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }

    // Helper function to recursively print the tree in-order
    void inorderTraversal(BinaryTreeNode<T>* node) const {
        if (node == nullptr) return;
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }

public:
    // Constructor
    BinaryTree() : root(nullptr) {}

    // Destructor
    ~BinaryTree() {
        deleteTree(root);
    }

    // Insert a new node in the binary tree
    void insert(T value) {
        BinaryTreeNode<T>* newNode = new BinaryTreeNode<T>(value);
        if (root == nullptr) {
            root = newNode;
            return;
        }
        
        BinaryTreeNode<T>* current = root;
        while (true) {
            if (value < current->data) {
                if (current->left == nullptr) {
                    current->left = newNode;
                    break;
                } else {
                    current = current->left;
                }
            } else {
                if (current->right == nullptr) {
                    current->right = newNode;
                    break;
                } else {
                    current = current->right;
                }
            }
        }
    }

    // Print the tree in-order
    void inorderTraversal() const {
        inorderTraversal(root);
        cout << endl;
    }
};

// Main function to test the Binary Tree
int main() {
    BinaryTree<int> tree;

    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    cout << "In-order traversal of the tree: ";
    tree.inorderTraversal();

    return 0;
}

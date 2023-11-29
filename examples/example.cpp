#include <iostream>

// Definition of the Node class
class Node {
public:
    int data;
    Node* left, * right, * parent;

    Node(int data, Node* left = nullptr, Node* right = nullptr) {
        this->data = data;
        this->left = left;
        if (this->left != nullptr) {
            this->left->parent = this;
        }

        this->right = right;
        if (this->right != nullptr) {
            this->right->parent = this;
        }

        this->parent = nullptr;
    }
};

void iterativeInorder(Node* root) {
    Node* cur = root;

    // Find the leftmost node
    while (cur && cur->left) {
        cur = cur->left;
    }

    while (cur) {
        std::cout << cur->data << " "; // Output the data

        // Traverse the right subtree
        if (cur->right) {
            cur = cur->right;
            while (cur->left) {
                cur = cur->left;
            }
        } else {
            // Move up the tree
            while (cur->parent && cur == cur->parent->right) {
                cur = cur->parent;
            }
            cur = cur->parent;
        }
    }
}

// Example usage in main function
int main() {
    // Example to create a binary tree and call iterativeInorder
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n2 = new Node(2, n4, n5);
    Node* n3 = new Node(3);
    Node* root = new Node(1, n2, n3);
    //     1
    //    / \
    //   2   3
    //  / \
    // 4   5

    iterativeInorder(root);
    std::cout << std::endl;
}

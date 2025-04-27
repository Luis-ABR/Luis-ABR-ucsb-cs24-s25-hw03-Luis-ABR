#include "intbst.h"

// Constructor
IntBST::IntBST() : root(nullptr) {}

// Destructor
IntBST::~IntBST() {
    // Free all nodes
    while (root != nullptr) {
        insert(root, 0);  // dummy operation to trigger recursive deletion
    }
}

// Public insert
void IntBST::insert(int value) {
    insert(root, value);
}

// Private insert
void IntBST::insert(Node*& node, int value) {
    if (node == nullptr) {
        node = new Node(value);
    } else if (value < node->data) {
        insert(node->left, value);
    } else {
        insert(node->right, value);
    }
}

// Public printInOrder
void IntBST::printInOrder() const {
    if (!root) {
        cout << endl;
        return;
    }
    printInOrder(root);
    cout << endl;
}

// Private printInOrder
void IntBST::printInOrder(Node* node) const {
    if (!node) return;
    printInOrder(node->left);
    cout << node->data << " ";
    printInOrder(node->right);
}

// Public printPostOrder
void IntBST::printPostOrder() const {
    if (!root) {
        cout << endl;
        return;
    }
    printPostOrder(root);
    cout << endl;
}

// Private printPostOrder
void IntBST::printPostOrder(Node* node) const {
    if (!node) return;
    printPostOrder(node->left);
    printPostOrder(node->right);
    cout << node->data << " ";
}

// Public count
int IntBST::count() const {
    int total = count(root);
    cout << "Count is: " << total << endl;
    return total;
}

// Private count
int IntBST::count(Node* node) const {
    if (!node) return 0;
    return 1 + count(node->left) + count(node->right);
}

// Public sum
int IntBST::sum() const {
    int total = sum(root);
    cout << "Sum is: " << total << endl;
    return total;
}

// Private sum
int IntBST::sum(Node* node) const {
    if (!node) return 0;
    return node->data + sum(node->left) + sum(node->right);
}

// Public contains
bool IntBST::contains(int value) const {
    bool found = contains(root, value);
    if (found) {
        cout << value << " found in bst" << endl;
    } else {
        cout << value << " not found in bst" << endl;
    }
    return found;
}

// Private contains
bool IntBST::contains(Node* node, int value) const {
    if (!node) return false;
    if (node->data == value) return true;
    if (value < node->data) return contains(node->left, value);
    else return contains(node->right, value);
}

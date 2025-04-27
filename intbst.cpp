#include "intbst.h"

IntBST::IntBST() : root(nullptr) { }

IntBST::~IntBST() {
    clear();
}

void IntBST::destructorHelper(Node* n) {
    if (!n) return;
    destructorHelper(n->left);
    destructorHelper(n->right);
    delete n;
}

bool IntBST::insert(int value) {
    return insertHelper(root, value);
}

bool IntBST::insertHelper(Node*& n, int value) {
    if (!n) {
        n = new Node(value);
        return true;
    }
    if (value < n->data) {
        return insertHelper(n->left, value);
    }
    else if (value > n->data) {
        return insertHelper(n->right, value);
    }
    else {
        return false; // already in tree
    }
}

void IntBST::printInOrder() const {
    if (!root) {
        // Print nothing for empty tree
        return;
    }
    
    printInOrderHelper(root);
}

void IntBST::printInOrderHelper(Node* n) const {
    if (!n) return;
    
    if (n->left) {
        printInOrderHelper(n->left);
        cout << " ";
    }
    
    cout << n->data;
    
    if (n->right) {
        cout << " ";
        printInOrderHelper(n->right);
    }
}

void IntBST::printPostOrder() const {
    if (!root) {
        // Print nothing for empty tree
        return;
    }
    
    printPostOrderHelper(root);
}

void IntBST::printPostOrderHelper(Node* n) const {
    if (!n) return;
    
    if (n->left) {
        printPostOrderHelper(n->left);
        cout << " ";
    }
    
    if (n->right) {
        printPostOrderHelper(n->right);
        cout << " ";
    }
    
    cout << n->data;
}

int IntBST::count() const {
    return countHelper(root);
}

int IntBST::countHelper(Node* n) const {
    if (!n) return 0;
    return 1 + countHelper(n->left) + countHelper(n->right);
}

int IntBST::sum() const {
    return sumHelper(root);
}

int IntBST::sumHelper(Node* n) const {
    if (!n) return 0;
    return n->data + sumHelper(n->left) + sumHelper(n->right);
}

bool IntBST::contains(int value) const {
    return containsHelper(root, value);
}

bool IntBST::containsHelper(Node* n, int value) const {
    if (!n) return false;
    if (n->data == value) return true;
    else if (value < n->data) return containsHelper(n->left, value);
    else return containsHelper(n->right, value);
}

void IntBST::clear() {
    destructorHelper(root);
    root = nullptr;
}

// Find minimum value node in a subtree
IntBST::Node* IntBST::findMin(Node* node) const {
    if (!node) return nullptr;
    while (node->left) {
        node = node->left;
    }
    return node;
}

// Find maximum value node in a subtree
IntBST::Node* IntBST::findMax(Node* node) const {
    if (!node) return nullptr;
    while (node->right) {
        node = node->right;
    }
    return node;
}

// Find predecessor for a given value
IntBST::Node* IntBST::findPredecessor(int value) const {
    if (!root) return nullptr;
    
    Node* target = nullptr;
    Node* predecessor = nullptr;
    Node* current = root;
    
    // First find the node with the target value
    while (current && current->data != value) {
        if (value < current->data) {
            current = current->left;
        } else {
            predecessor = current;  // Potential predecessor
            current = current->right;
        }
    }
    
    if (!current) return nullptr;  // Value not found
    target = current;
    
    // If node has a left subtree, predecessor is the max in that subtree
    if (target->left) {
        return findMax(target->left);
    }
    
    // Otherwise, predecessor is the last node we came from when going right
    return predecessor;
}

// Find successor for a given value
IntBST::Node* IntBST::findSuccessor(int value) const {
    if (!root) return nullptr;
    
    Node* target = nullptr;
    Node* successor = nullptr;
    Node* current = root;
    
    // First find the node with the target value
    while (current && current->data != value) {
        if (value > current->data) {
            current = current->right;
        } else {
            successor = current;  // Potential successor
            current = current->left;
        }
    }
    
    if (!current) return nullptr;  // Value not found
    target = current;
    
    // If node has a right subtree, successor is the min in that subtree
    if (target->right) {
        return findMin(target->right);
    }
    
    // Otherwise, successor is the last node we came from when going left
    return successor;
}

int IntBST::getPredecessor(int value) const {
    Node* pred = findPredecessor(value);
    if (pred) {
        return pred->data;
    }
    return 0;  // Default value when no predecessor
}

int IntBST::getSuccessor(int value) const {
    Node* succ = findSuccessor(value);
    if (succ) {
        return succ->data;
    }
    return 0;  // Default value when no successor
}

bool IntBST::remove(int value) {
    bool result = removeHelper(root, value);
    return result;
}

bool IntBST::removeHelper(Node*& node, int value) {
    if (!node) return false;
    
    if (value < node->data) {
        return removeHelper(node->left, value);
    } 
    else if (value > node->data) {
        return removeHelper(node->right, value);
    }
    else {
        // Case 1: Leaf node
        if (!node->left && !node->right) {
            delete node;
            node = nullptr;
        }
        // Case 2: One child
        else if (!node->left) {
            Node* temp = node;
            node = node->right;
            delete temp;
        }
        else if (!node->right) {
            Node* temp = node;
            node = node->left;
            delete temp;
        }
        // Case 3: Two children
        else {
            // Find successor (minimum value in right subtree)
            Node* successor = findMin(node->right);
            node->data = successor->data;
            removeHelper(node->right, successor->data);
        }
        return true;
    }
}

void IntBST::printInOrderReverse() const {
    printInOrderReverseHelper(root);
}

void IntBST::printInOrderReverseHelper(Node* node) const {
    if (!node) return;
    
    printInOrderReverseHelper(node->right);
    cout << node->data << " ";
    printInOrderReverseHelper(node->left);
}

void IntBST::printAlternate() const {
    printAlternateHelper(root);
}

void IntBST::printAlternateHelper(Node* node) const {
    if (!node) return;
    
    cout << node->data << " ";
    
    Node* successor = findSuccessor(node->data);
    Node* predecessor = findPredecessor(node->data);
    
    if (successor) {
        cout << successor->data << " ";
    }
    
    if (predecessor) {
        cout << predecessor->data << " ";
    }
    
    // Continue with children
    printAlternateHelper(node->left);
    printAlternateHelper(node->right);
}
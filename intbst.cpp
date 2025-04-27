#include "intbst.h"

IntBST::IntBST() : root(0) { }

IntBST::~IntBST() {
    destructorHelper(root);
}

void IntBST::destructorHelper(Node* n) {
    if (!n) return;
    destructorHelper(n->left);
    destructorHelper(n->right);
    delete n;
}

bool IntBST::insert(int value) {
    return insert(root, value);
}

bool IntBST::insert(Node*& n, int value) {
    if (!n) {
        n = new Node(value);
        return true;
    }
    if (value < n->data) {
        return insert(n->left, value);
    }
    else if (value > n->data) {
        return insert(n->right, value);
    }
    else {
        return false; // already in tree
    }
}

void IntBST::printInOrder() const {
    bool isFirst = true;
    printInOrderHelper(root, isFirst);
}

void IntBST::printInOrder(Node* n) const {
    // not used in fixed version
}

void IntBST::printInOrderHelper(Node* n, bool& isFirst) const {
    if (!n) return;
    printInOrderHelper(n->left, isFirst);
    if (!isFirst) cout << " ";
    cout << n->data;
    isFirst = false;
    printInOrderHelper(n->right, isFirst);
}

void IntBST::printPostOrder() const {
    bool isFirst = true;
    printPostOrderHelper(root, isFirst);
}

void IntBST::printPostOrder(Node* n) const {
    // not used in fixed version
}

void IntBST::printPostOrderHelper(Node* n, bool& isFirst) const {
    if (!n) return;
    printPostOrderHelper(n->left, isFirst);
    printPostOrderHelper(n->right, isFirst);
    if (!isFirst) cout << " ";
    cout << n->data;
    isFirst = false;
}

int IntBST::sum() const {
    return sum(root);
}

int IntBST::sum(Node* n) const {
    if (!n) return 0;
    return n->data + sum(n->left) + sum(n->right);
}

int IntBST::count() const {
    return count(root);
}

int IntBST::count(Node* n) const {
    if (!n) return 0;
    return 1 + count(n->left) + count(n->right);
}

bool IntBST::contains(int value) const {
    return contains(root, value);
}

bool IntBST::contains(Node* n, int value) const {
    if (!n) return false;
    if (n->data == value) return true;
    else if (value < n->data) return contains(n->left, value);
    else return contains(n->right, value);
}

void IntBST::clear() {
    destructorHelper(root);
    root = nullptr;
}

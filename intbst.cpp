#include "intbst.h"

// constructor
IntBST::IntBST() : root(nullptr) { }

// destructor
IntBST::~IntBST() {
    clear(root);
}

// recursive clear function
void IntBST::clear(Node* n) {
    if (!n) return;
    clear(n->left);
    clear(n->right);
    delete n;
}

// insert value
bool IntBST::insert(int value) {
    if (!root) {
        root = new Node(value);
        return true;
    }
    Node* curr = root;
    while (curr) {
        if (value < curr->data) {
            if (!curr->left) {
                curr->left = new Node(value);
                return true;
            }
            curr = curr->left;
        }
        else if (value > curr->data) {
            if (!curr->right) {
                curr->right = new Node(value);
                return true;
            }
            curr = curr->right;
        }
        else {
            return false; // duplicate
        }
    }
    return false;
}

// public pre-order
void IntBST::printPreOrder() const {
    printPreOrder(root);
    cout << endl;
}

// private helper pre-order
void IntBST::printPreOrder(Node* n) const {
    if (!n) return;
    cout << n->data << " ";
    printPreOrder(n->left);
    printPreOrder(n->right);
}

// public in-order
void IntBST::printInOrder() const {
    printInOrder(root);
    cout << endl;
}

// private helper in-order
void IntBST::printInOrder(Node* n) const {
    if (!n) return;
    printInOrder(n->left);
    cout << n->data << " ";
    printInOrder(n->right);
}

// public post-order
void IntBST::printPostOrder() const {
    printPostOrder(root);
    cout << endl;
}

// private helper post-order
void IntBST::printPostOrder(Node* n) const {
    if (!n) return;
    printPostOrder(n->left);
    printPostOrder(n->right);
    cout << n->data << " ";
}

// find node for a value
IntBST::Node* IntBST::getNodeFor(int value, Node* n) const {
    if (!n) return nullptr;
    if (n->data == value) return n;
    if (value < n->data) return getNodeFor(value, n->left);
    else return getNodeFor(value, n->right);
}

// public contains
bool IntBST::contains(int value) const {
    return getNodeFor(value, root) != nullptr;
}

// sum helper
int IntBST::sum(Node* n) const {
    if (!n) return 0;
    return n->data + sum(n->left) + sum(n->right);
}

// public sum
int IntBST::sum() const {
    return sum(root);
}

// count helper
int IntBST::count(Node* n) const {
    if (!n) return 0;
    return 1 + count(n->left) + count(n->right);
}

// public count
int IntBST::count() const {
    return count(root);
}

// getPredecessor
int IntBST::getPredecessor(int value) const {
    Node* curr = getNodeFor(value, root);
    if (!curr) return 0;

    if (curr->left) {
        curr = curr->left;
        while (curr->right) curr = curr->right;
        return curr->data;
    }
    else {
        Node* ancestor = root;
        Node* pred = nullptr;
        while (ancestor != curr) {
            if (value > ancestor->data) {
                pred = ancestor;
                ancestor = ancestor->right;
            } else {
                ancestor = ancestor->left;
            }
        }
        return pred ? pred->data : 0;
    }
}

// getSuccessor
int IntBST::getSuccessor(int value) const {
    Node* curr = getNodeFor(value, root);
    if (!curr) return 0;

    if (curr->right) {
        curr = curr->right;
        while (curr->left) curr = curr->left;
        return curr->data;
    }
    else {
        Node* ancestor = root;
        Node* succ = nullptr;
        while (ancestor != curr) {
            if (value < ancestor->data) {
                succ = ancestor;
                ancestor = ancestor->left;
            } else {
                ancestor = ancestor->right;
            }
        }
        return succ ? succ->data : 0;
    }
}

// remove a value
bool IntBST::remove(int value) {
    Node* parent = nullptr;
    Node* curr = root;

    while (curr && curr->data != value) {
        parent = curr;
        if (value < curr->data) curr = curr->left;
        else curr = curr->right;
    }
    if (!curr) return false; // not found

    if (!curr->left && !curr->right) {
        if (!parent) root = nullptr;
        else if (parent->left == curr) parent->left = nullptr;
        else parent->right = nullptr;
        delete curr;
    }
    else if (curr->left && !curr->right) {
        if (!parent) root = curr->left;
        else if (parent->left == curr) parent->left = curr->left;
        else parent->right = curr->left;
        delete curr;
    }
    else if (!curr->left && curr->right) {
        if (!parent) root = curr->right;
        else if (parent->left == curr) parent->left = curr->right;
        else parent->right = curr->right;
        delete curr;
    }
    else {
        int succData = getSuccessor(curr->data);
        curr->data = succData;
        remove(succData); // remove duplicate successor
    }
    return true;
}

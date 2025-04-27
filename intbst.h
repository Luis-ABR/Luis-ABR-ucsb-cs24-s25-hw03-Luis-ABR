// intbst.h

#ifndef INTBST_H
#define INTBST_H

#include <iostream>
using namespace std;

class IntBST {

private:
    struct Node {
        int data;
        Node* left;
        Node* right;
        Node(int d) : data(d), left(nullptr), right(nullptr) {}
    };

    Node* root;

public:
    IntBST();              // constructor
    ~IntBST();             // destructor

    bool insert(int value);
    void printPreOrder() const;
    void printInOrder() const;
    void printPostOrder() const;
    int sum() const;
    int count() const;
    bool contains(int value) const;
    int getPredecessor(int value) const;
    int getSuccessor(int value) const;
    bool remove(int value);

private:
    // helper functions
    void printPreOrder(Node* n) const;
    void printInOrder(Node* n) const;
    void printPostOrder(Node* n) const;
    int sum(Node* n) const;
    int count(Node* n) const;
    Node* getNodeFor(int value, Node* n) const;
    void clear(Node* n);
};

#endif

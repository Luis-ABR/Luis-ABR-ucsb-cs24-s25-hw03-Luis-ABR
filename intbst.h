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
        Node(int d) : data(d), left(0), right(0) { }
    };

    Node* root;

public:
    IntBST();
    ~IntBST();

    bool insert(int value);
    void printInOrder() const;
    void printPostOrder() const;
    int sum() const;
    int count() const;
    bool contains(int value) const;
    void clear();

private:
    void destructorHelper(Node* n);
    bool insert(Node*& n, int value);
    void printInOrder(Node* n) const;
    void printPostOrder(Node* n) const;
    void printInOrderHelper(Node* n, bool& isFirst) const;
    void printPostOrderHelper(Node* n, bool& isFirst) const;
    int sum(Node* n) const;
    int count(Node* n) const;
    bool contains(Node* n, int value) const;
};

#endif

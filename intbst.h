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

    void insert(Node*& node, int value);
    void printInOrder(Node* node) const;
    void printPostOrder(Node* node) const;
    int count(Node* node) const;
    int sum(Node* node) const;
    bool contains(Node* node, int value) const;

public:
    IntBST();
    ~IntBST();
    void insert(int value);
    void printInOrder() const;
    void printPostOrder() const;
    int count() const;
    int sum() const;
    bool contains(int value) const;
};

#endif

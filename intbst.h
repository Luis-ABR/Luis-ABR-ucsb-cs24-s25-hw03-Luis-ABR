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

    // Private helper methods
    bool insertHelper(Node*& node, int value);
    void printInOrderHelper(Node* node) const;
    void printPostOrderHelper(Node* node) const;
    int countHelper(Node* node) const;
    int sumHelper(Node* node) const;
    bool containsHelper(Node* node, int value) const;
    void destructorHelper(Node* node);
    Node* findPredecessor(int value) const;
    Node* findSuccessor(int value) const;
    Node* findMin(Node* node) const;
    Node* findMax(Node* node) const;
    bool removeHelper(Node*& node, int value);
    void printInOrderReverseHelper(Node* node) const;
    void printAlternateHelper(Node* node) const;

public:
    IntBST();
    ~IntBST();
    bool insert(int value);
    void printInOrder() const;
    void printPostOrder() const;
    int count() const;
    int sum() const;
    bool contains(int value) const;
    void clear();
    int getPredecessor(int value) const;
    int getSuccessor(int value) const;
    bool remove(int value);
    void printInOrderReverse() const;
    void printAlternate() const;
};

#endif
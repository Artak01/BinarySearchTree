#ifndef BST_H
#define BST_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

template <typename T>
class BST {
private:
    struct Node {
        T val;
        Node* left;
        Node* right;

        Node(T val) 
            : val(val) 
            , left(nullptr) 
            , right(nullptr) 
        {}
    };

    Node* root;

    Node* insert(Node*& node, T value);
    Node* search(Node* node, T value) const;
    void inorder(Node* node) const;
    void preorder(Node* node) const;
    void postorder(Node* node) const;
    void clear(Node* node);
    Node* deleteNode(Node* node, T value);
    Node* getMin(Node* node) const;
    Node* getMax(Node* node) const;
    int getHeight(Node* node) const;
    int getSize(Node* node) const;
    Node* getPredecessor(Node* node, T value) const;
    Node* getSuccessor(Node* node, T value) const;
public:
    BST();
    ~BST();
    
    void insert(T value);
    bool search(T value) const;
    void inorder() const;
    void preorder() const;
    void postorder() const;
    void deleteValue(T value);
    int getHeight() const;
    int getSize() const;
    T getPredecessor(T value) const;
    T getSuccessor(T value) const;
};

#include "bst.cpp"
#endif
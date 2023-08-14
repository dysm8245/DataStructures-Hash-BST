#ifndef BST_H
#define BST_H
#include<iostream>

using namespace std;

struct Node{
    int key;
    Node *left;
    Node *right;
};

class bst{
    private:
        Node *root;
    public:
        void insertNode(int num);
        void searchKey(int num);
        void printTree();
};


#endif
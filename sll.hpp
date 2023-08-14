#ifndef SLL_H
#define SLL_H
#include<iostream>

using namespace std;

struct Node{
    int key;
    Node *next;
};

class sll{
    private:
        Node *head;
    public:
        void insertNode(int num);
        void searchKey(int num);
        void printPath();
};

#endif
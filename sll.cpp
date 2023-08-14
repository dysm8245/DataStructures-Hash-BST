#include <iostream>
#include "sll.hpp"
#include <string>


void sll::insertNode(int num)
{
    Node *item = new Node;
    item->key = num;
    if(head == NULL){
        item->next = head;
        head = item;
    }
    else{
        Node *current = head;
        while(current){
            if(current->next == NULL){
                current->next = item;
                item->next = NULL;
            }
            current = current->next;
        }
    }
}

void sll::searchKey(int num){
    Node *current = head;
    while(current != NULL){
        if(current->key == num){
            return;
        }
        current = current->next;
    }
}

void sll::printPath()
{
    Node *current = head;
    cout << "== CURRENT PATH ==" << endl;
    while(current != NULL){
        cout << current->key << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl; 
    cout << "===" << endl;
}

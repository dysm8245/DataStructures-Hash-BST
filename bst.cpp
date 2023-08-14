#include <iostream>
#include "bst.hpp"

using namespace std;
//helper for search
void getItem(Node *item, int num){
  if(item->key == num){
    return;
  }
  else if(item->key > num){
    getItem(item->left, num);
  }
  else if(item->key < num){
    getItem(item->right, num);
  }
}
//searches
void bst::searchKey(int num)
{
    // Your code here
    getItem(root, num);
}

Node *insertNodeHelper(Node *item, int num){
  if(item == NULL){
    //creates node
    Node *newitem = new Node;
    newitem->key = num;
    item = newitem;
    item->left = NULL;
    item->right = NULL;
  }
  else if(item->key >= num){
    item->left = insertNodeHelper(item->left, num);
  }
  else if(item->key <= num){
    item->right = insertNodeHelper(item->right, num);
  }
  return item;
}
//inserts node
void bst::insertNode(int num)
{
    // Your code here
    root = insertNodeHelper(root, num);
}

void printTreeHelper(Node *item){
  if(item){
    printTreeHelper(item->left);
    cout << item->key << ", "; 
    printTreeHelper(item->right);
  }
}
//prints tree
void bst::printTree()
{
    // Your code here
    if(root == NULL){
        cout << "Tree is Empty. Cannot print" << endl;
    }
    printTreeHelper(root);
}
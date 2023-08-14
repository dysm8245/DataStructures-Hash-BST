#include <iostream>
#include "hashchain.hpp"

using namespace std;
//creates an item
node* HashTable::createNode(int num){
    node *item = new node;
    item->key = num;
    item->next = NULL;
    return item;
}
//constructs table
HashTable::HashTable(int size){
    tableSize = size;
    table = new node*[tableSize];
    for(int i = 0; i < tableSize; i++){
        table[i] = NULL;
    }
    numOfcollisioni = 0;
    numOfcollisions = 0;
}

bool HashTable::insertItem(int key){
    int index = hashFunction(key);
    node *item = createNode(key);
    //first item in index
    if(table[index] == NULL){
        table[index] = item;
        return true;
    }
    //finds end of linked list
    else{
        node *current = table[index];
        while(current){
            numOfcollisioni++;
            if(current->next == NULL){
                current->next = item;
                item->next = NULL;
            }
            current = current->next;
        }
        return true;
    }

}
//finds index where item will be placed
unsigned int HashTable::hashFunction(int key){
    int index = key % tableSize;
    return index;
}
//prints all items
void HashTable::printTable(){
    for(int i = 0; i < tableSize; i++){
        node *current = table[i];
        while(current){
            cout << current->key << ", ";
            current = current->next;
        }
    }
}

int HashTable::getNumOfCollisioni(){
    return numOfcollisioni;
}
int HashTable::getNumOfCollisions(){
    return numOfcollisions;
}

node* HashTable::searchItem(int num){
    int index = hashFunction(num);
    node* current = table[index];
    if(current == NULL){
        cout << "Item not in table." << endl;
    }
    //searches linked list
    else{
        while(current){
            numOfcollisions++;
            if(current->key == num){
                return table[index];
            }
            else if(current->next == NULL){
                cout << "Item not in table." << endl;
                return NULL;
            }
            current = current->next;
        }
    }
    return table[index];
}


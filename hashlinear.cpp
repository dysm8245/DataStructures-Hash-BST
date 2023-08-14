#include <iostream>
#include "hashlinear.hpp"

using namespace std;

node* HashTable::createNode(int num){
    node *item = new node;
    item->key = num;
    item->next = NULL;
    return item;
}

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
    if(table[index] == NULL){
        table[index] = item;
        return true;
    }
    else{
        bool flag = 1;
        int newindex;
        int count = 1;
        //finds empty index with linear probing
        while(flag){
            numOfcollisioni++;
            newindex = (index + count)%tableSize;
            count++;
            if(newindex == tableSize){
                count = 0;
                index = 0;
            }
            if(table[newindex] == NULL){
                table[newindex] = item;
                flag = 0;
            }
        }
        return true;
    }

}

unsigned int HashTable::hashFunction(int key){
    int index = key % tableSize;
    return index;
}

void HashTable::printTable(){
    for(int i = 0; i < tableSize; i++){
        node *current = table[i];
        if(current != NULL){
            cout << current->key << ", ";
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
        return NULL;
    }
    else if(current->key == num){
        return table[index];
    }
    else{
        bool flag = 1;
        int newindex;
        int count = 1;
        int count2 = 0;
        //probes through linearally for item
        while(flag){
            numOfcollisions++;
            newindex = (index + count)%tableSize;
            count++;
            count2++;
            if(newindex == 10009){
                index = 0;
                count = 0;
            }
            if(table[newindex]->key == num){
                flag = 0;
                return table[newindex];
            }
            if(count2 == 10009){
                cout << "Item not in table." << endl;
                flag = 0;
                return NULL;
            }
        }
    }
    return table[index];
}


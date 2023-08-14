#ifndef HASHCHAIN_HPP
#define HASHCHAIN_HPP

#include <string>


using namespace std;

struct node
{
    int key;
    struct node* next = NULL;
};

class HashTable
{
    private:
        int tableSize;  // No. of buckets (linked lists)
        // Pointer to an array containing buckets
        node **table;
        int numOfcollisioni;
        int numOfcollisions;
    public:
        node* createNode(int key);
        // Constructor
        HashTable(int size);
        // inserts a key into hash table
        bool insertItem(int key);
        // hash function to map values to key
        unsigned int hashFunction(int key);
        void printTable();
        int getNumOfCollisions();
        int getNumOfCollisioni();
        node* searchItem(int key);
};

#endif

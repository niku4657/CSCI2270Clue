#ifndef HASH_HPP
#define HASH_HPP

#include <string>


using namespace std;

struct Card
{
    int key;
    string name;
    struct Card* next;

};

class HashTable
{
    int tableSize = 18;  // No. of buckets (linked lists)

    // Pointer to an array containing buckets
    Card* *table;

    Card* createCard(int key, string name, Card* next);
public:
    HashTable();  // Constructor

    //void showCard(int key, string name); // Person A's card inserted into Person B's

    // inserts a key into hash table
    bool insertItem(int key, string name);

    // hash function to map values to key
    unsigned int hashFunction(int key);

    void printTable();

    Card* searchItem(int key, string name);

    Card* searchItem(int key);
};

#endif

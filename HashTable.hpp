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
public:
    int tableSize = 18;

    Card* *table;

    HashTable();

    Card* createCard(int key, string name, Card* next);

    bool insertItem(int key, string name);

    unsigned int hashFunction(int key);

    void printTable();

    Card* searchItem(int key, string name);

    Card* searchItem(int key);
};

#endif

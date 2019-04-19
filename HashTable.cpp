// CPP program to implement hashing with chaining
#include<iostream>
#include "HashTable.hpp"
using namespace std;

// function to display hash table
void HashTable::printTable()
{
    for (int i = 0; i < tableSize; i++) {
        cout << i <<"|| ";

        Card* temp;
        temp = table[i];
        while (temp != NULL)
        {
            cout << "CARD" << endl;
            cout << temp -> key << ": ";
            cout << temp -> name << endl;
            temp = temp -> next;
        }
        cout << endl;
    }

 }

Card* HashTable::createCard(int key, string name, Card* next)
{
    Card* nw = new Card;
    nw->key = key;
    nw->name = name;
    nw->next = next;
    return nw;
}

HashTable::HashTable()
{
    table = new Card*[tableSize];
    for(int i=0;i<tableSize;i++)
        table[i] = nullptr;
}

//function to calculate hash function
unsigned int HashTable::hashFunction(int key)
{
    return (key / 6);
}

//function to insert
bool HashTable::insertItem(int key, string name)
{
    if(!searchItem(key))
    {
        // Use the hash function on the key to get the index/slot,
        // create a new Card with the key and insert it in this slot's list
        int index = hashFunction(key);

        Card* temp = table[index];

        if (temp == NULL)
        {
            table[index] = createCard(key, temp, NULL);
            return true;
        }
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = createCard(key, name, NULL);
        return true;
     }
    else
    {
        cout << "Duplicate Entry: " << key << endl;
        return false;
    }

}

//function to search
Card* HashTable::searchItem(int key, string name)
{
    //Compute the index by using the hash function
    int index = hashFunction(key);

    // Search the list at that specific index and return the Card if found
    Card* temp = table[index];

    while (temp != NULL)
    {
        if (temp -> name == name) return temp;
        temp = temp -> next;
    }

    return NULL;
}

Card* HashTable::searchItem(int key)
{
    //Compute the index by using the hash function
    int index = hashFunction(key);

    // Search the list at that specific index and return the Card if found
    Card* temp = table[index];

    while (temp != NULL)
    {
        if (temp -> key == key) return temp;
        temp = temp -> next;
    }
    return NULL;
}

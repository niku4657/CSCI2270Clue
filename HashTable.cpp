// CPP program to implement hashing with chaining
#include<iostream>
#include "HashTable.hpp"
using namespace std;

HashTable::HashTable()
{
    table = new Card*[tableSize];
    for(int i = 0; i < tableSize; i++)
    {
      table[i] = nullptr;
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

bool HashTable::insertItem(int key, string name)
{
    if(!searchItem(key))
    {
        int index = hashFunction(key);

        Card* temp = table[index];

        if (temp == NULL)
        {
            table[index] = createCard(key, name, NULL);
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

unsigned int HashTable::hashFunction(int key)
{
    return (key / 6);
}

void HashTable::printTable()
{
    for (int i = 0; i < tableSize; i++)
    {
      if(i == 0)
      {
        cout << "Weapons: " << endl;
      }
      else if(i == 1)
      {
        cout << "Suspects: " << endl;;
      }
      else
      {
        cout << "Rooms: " << endl;
      }

      Card* temp;

      temp = table[i];

      while (temp != NULL)
      {
          cout << temp -> name << " || ";
          temp = temp -> next;
      }

      cout << endl << endl;
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
        if (temp -> name == name)
        {
          return temp;
        }

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

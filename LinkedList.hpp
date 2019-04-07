#ifndef THECARD_HPP
#define THECARD_HPP
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

struct Card {
    string name;
    string type;
    Card *next;
};

class LinkedList
{
  private:
    Card *head;

  public:
    LinkedList()
    {
    	head = NULL;
    }
    void insert(string name, string type);
    bool delete(string name);
    void printList();
};

#endif

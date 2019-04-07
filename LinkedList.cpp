#include <cstring>
#include <iostream>
#include <string>
#include "LinkedList.hpp"
using namespace std;

void LinkedList::insert(string name, string type)
{
  Card* newCard = new Card;
  newCard -> name = name;
  newCard -> type = type;
  newCard -> next = NULL;

  if(head == NULL)
  {
    head = newNode;
    return;
  }

  Card* temp = head;

  while(temp -> next != NULL)
  {
    temp = temp -> next;
  }

  temp -> next = newCard;
  return;
}

bool LinkedList::deleteAtHead()
{
	bool isDeleted = false;

  if(head == NULL){
    cout<< "List is already empty"<<endl;
    return isDeleted;
  }

  Node *temp = head;
	head = temp->next;
	delete temp;
  isDeleted = true;

	return isDeleted;
}

bool LinkedList::delete(string name)
{
  bool isDeleted = false;

  if(head == NULL)
  {
    cout << "List is already empty" << endl;
    return isDeleted;
  }

	Card *pres = head;
	Card *prev = NULL;

 if (head -> name == name)
 {
   pres = head;
   head = head -> next;
   delete pres;
 }
 else
 {
   pres = head;
   prev = head -> next;
   while (prev != NULL)
   {
     if (prev -> name == name)
     {
       if (prev -> next == NULL)
       {
         pres -> next = NULL;
       }
       else
       {
         pres -> next = prev -> next;
       }
       delete prev;
       isDeleted = true;
       break;
     }
     else
     {
       pres = prev;
       prev = prev -> next;
     }
   }
 }
	return isDeleted;
}

void LinkedList::printList()
{
  Card* temp = head;

  while(temp -> next != NULL)
  {
    cout << temp -> name << " -> ";
    temp = temp -> next;
  }

  cout << temp -> name << endl;
}

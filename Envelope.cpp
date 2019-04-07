#include <iostream>
#include <string>

using namespace std;

struct Card {
    string name;
    string type;
};

struct Node{
      int key;
      Node *next;
};

class LinkedList
{
  private:
    Node *head;

  public:
    LinkedList(){
    	head = NULL;
    }
    void insert_begin(int newKey);
    void insert_end(int newKey);
    bool deleteAtIndex(int index);
  	bool deleteAtHead();
    void printList();
};

void LinkedList::insert_begin(int newKey){
  //1. ALLOCATE NODE
  Node* newNode = new Node;

  //2. PUT IN THE DATA
  newNode->key = newKey;

  //3. Make next of newNode as head
  newNode->next = head;

  //4. Change the head to newNode
  head = newNode;
}

void LinkedList::insert_end(int newKey){
  //1. ALLOCATE NODE
  Node* newNode = new Node;

  //2. PUT IN THE DATA
  newNode->key = newKey;

  //3. Make next of newNode as NULL
  newNode->next = NULL;

  //4. Check if head is not Null
  if(head == NULL){
    head = newNode;
    return;
  }

  //4. Traverse the LinkedList till end
  Node* temp = head;

  while(temp->next != NULL){
    temp = temp->next;
  }
  temp->next = newNode;
  return;
}

// Use deleteAtHead to delete the first item in the list
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

//TODO
bool LinkedList::deleteAtIndex(int n)
{
  bool isDeleted = false;

  if(head == NULL){
    cout<< "List is already empty"<<endl;
    return isDeleted;
  }

	Node *pres = head;
	Node *prev = NULL;

  //TODO Complete this function
 if (head->key == n){
   pres = head;
   head = head->next;
   delete pres;
 }
 else{
   pres = head;
   prev = head->next;
   while (prev != NULL){
     if (prev->key == n){
       if (prev->next == NULL){
         pres->next = NULL;
       }
       else{
         pres->next = prev->next;
       }
       delete prev;
       isDeleted = true;
       break;
     }
     else{
       pres = prev;
       prev = prev->next;
     }
   }
 }
  //isDeleted = true;

	return isDeleted;
}

void LinkedList::printList(){
  Node* temp = head;

  while(temp->next != NULL){
    cout<< temp->key <<" -> ";
    temp = temp->next;
  }

  cout<<temp->key<<endl;
}

int main(){
    LinkedList weapon;
    LinkedList suspect;
    LinkedList building;
    LinkedList envelope;

    // create the cards
    // make random function, gets a random index
    // randomly add cards to 3 different linked lists (6 cards in each)
    // chose a random card from each list (one weapon, one suspect, one room/building)
    // put card in envelope and delete from original linked lists
}
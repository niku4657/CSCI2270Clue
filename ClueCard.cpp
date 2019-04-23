#include <iostream>
#include <vector>
#include "HashTable.hpp"
#include "ClueCard.hpp"
using namespace std;

ClueCard::ClueCard()
{
  //Leave empty.
}

ClueCard::~ClueCard()
{
  //Leave empty.
}

void ClueCard::addCardArray(Card cards[],int index, int _key, string _name)
{
  cards[index].key = _key;
  cards[index].name =_name;
  cards[index].next=NULL;
}

void ClueCard::fillInWeapons()
{
  addCardArray(weapon, 0, 0, "C4C Food");
  addCardArray(weapon, 1, 1, "Ralphie's Horn");
  addCardArray(weapon, 2, 2, "CSCI 2270 Midterm 2");
  addCardArray(weapon, 3, 3, "Dean's List");
  addCardArray(weapon, 4, 4, "Flu from the Dorms");
  addCardArray(weapon, 5, 5, "Freshmen Ego");

}

void ClueCard::fillInSuspects()
{
  addCardArray(suspect, 0, 6, "Ralphie");
  addCardArray(suspect, 1, 7, "Chip the Buffalo");
  addCardArray(suspect, 2, 8, "Mr. Gold");
  addCardArray(suspect, 3, 9, "Ms. Black");
  addCardArray(suspect, 4, 10, "Prashil");
  addCardArray(suspect, 5, 11, "Tanvi");

}

void ClueCard::fillInRooms()
{
  addCardArray(room, 0, 12, "UMC");
  addCardArray(room, 1, 13, "Farrand Field");
  addCardArray(room, 2, 14, "CSEL");
  addCardArray(room, 3, 15, "Kittredge");
  addCardArray(room, 4, 16, "Folsom Field");
  addCardArray(room, 5, 17, "C4C");

}

void ClueCard::printArray()
{
    for (int i = 0; i < 6; i++)
    {
        cout << weapon[i].key << ":" << weapon[i].name << endl;
    }
}

void deleteElement(Card cards[], int key, int size)
{
  int n = size;
  for (int i = 0; i < n; i++){
    if (cards[i].key == key){
      for (int j = i; j < n-1; j++){
        cards[j] = cards[j+1];
      }
      break;
    }
  }
}

void shuffleArray(Card cards[])
{
  for (int i=0; i < 5; i++)
  {
    int r = i + (rand() % (5 - i));
    Card temp = cards[i]; cards[i] = cards[r]; cards[r] = temp; // fisher-yates algorithm was the best to use
  }
}

void ClueCard::shuffleCards()
{
    int w = rand() % 5;
    // use rand function to get random index from 0 -5
    envelope -> insertItem(weapon[w].key, weapon[w].name);
    // add card to envelope: envelope.insertItem(cards[i].key, cards[i].name)
    deleteElement(weapon, weapon[w].key, 6);
    int s = rand() % 5;
    envelope -> insertItem(suspect[s].key, suspect[s].name);
    deleteElement(suspect, suspect[s].key, 6);
    int r = rand() % 5;
    envelope -> insertItem(room[r].key, room[r].name);
    deleteElement(room, room[r].key, 6);

    // delete card at index from array
    shuffleArray(weapon);
    shuffleArray(suspect);
    shuffleArray(room);
}

void ClueCard::mergeArrays()
{
  for (int i = 0; i < 15; i++)
  {
    if (i < 5)
    {
      allCards[i] = weapon[i];
    }
    else if(i >= 5 && i < 10)
    {
      allCards[i] = suspect[i - 5];
    }
    else if(i >= 10 && i < 15)
    {
      allCards[i] = room[i - 10];
    }
  }
}

bool ClueCard::checkEnvelope(string weapon, string suspect, string room)
{
  Card* cards[3];
  vector<Card*> notNull;

  cards[0] = envelope -> table[0];
  cards[1] = envelope -> table[1];
  cards[2] = envelope -> table[2];

  for(int i = 0; i < 3; i++)
  {
    if(cards[i] -> name == weapon || cards[i] -> name == suspect || cards[i] -> name == room)
    {
      notNull.push_back(cards[i]);
    }
  }

	if(notNull.size() == 3)
	{
    return true;
  }
  else
  {
    return false;
  }
}

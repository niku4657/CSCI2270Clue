#include <iostream>
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

void ClueCard::addCardArray(Card cards[], int _key, string _name)
{
  cards[_key] = {_key, _name};
}

void ClueCard::fillInWeapons()
{
  addCardArray(weapon, 0, "C4C Food");
  addCardArray(weapon, 1, "Ralphie's Horn");
  addCardArray(weapon, 2, "CSCI 2270 Midterm 2");
  addCardArray(weapon, 3, "Dean's List");
  addCardArray(weapon, 4, "Flu from the Dorms");
  addCardArray(weapon, 5, "Freshmen Ego");

}

void ClueCard::fillInSuspects()
{
  addCardArray(suspect, 6, "Ralphie");
  addCardArray(suspect, 7, "Chip the Buffalo");
  addCardArray(suspect, 8, "Mr. Gold");
  addCardArray(suspect, 9, "Ms. Black");
  addCardArray(suspect, 10, "Prashil");
  addCardArray(suspect, 11, "Tanvi");

}

void ClueCard::fillInRooms()
{
  addCardArray(room, 12, "UMC");
  addCardArray(room, 13, "Farrand Field");
  addCardArray(room, 14, "CSEL");
  addCardArray(room, 15, "Kittredge");
  addCardArray(room, 16, "Folsom Field");
  addCardArray(room, 17, "C4C");

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
    envelope -> insertItem(suspect[s].key, weapon[s].name);
    deleteElement(suspect, suspect[s].key, 6);

    int r = rand() % 5;
    envelope -> insertItem(room[r].key, room[r].name);
    deleteElement(room, room[r].key, 6);

    // delete card at index from array
    shuffleArray(weapon);
    shuffleArray(suspect);
    shuffleArray(room);
}

void ClueCard::mergeArrays(){
  for (int i = 0; i < 15; i++){
    if (i < 5){
      allCards[i] = weapon[i];
    }
    else if(i >= 5 && i < 10){
      allCards[i] = suspect[i - 5];
    }
    else if(i >= 10 && i < 15){
      allCards[i] = room[i-10];
    }
  }
}

bool ClueCard::checkEnvelope(string weapon, string suspect, string room)
{
	Card *w = envelope -> searchItem(0, weapon);
	Card *s = envelope -> searchItem(6, suspect);
	Card *r = envelope -> searchItem(12, room);

	if(w == NULL || s == NULL || r == NULL)
	{
		return false;
	}

	if(w != NULL && s != NULL && r != NULL)
	{
		return true;
	}
}

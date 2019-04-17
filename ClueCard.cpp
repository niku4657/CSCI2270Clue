#include <iostream>
#include "HashTable.hpp"
#include "ClueCard.hpp"

using namespace std;

void ClueCard::addCardArray(Card cards[], int _key, string _name){
  cards[_key] = {_key, _name};
}

void ClueCard::fillInWeapons(){
  addCardArray(weapon, 0, "C4C Food");
  addCardArray(weapon, 1, "Ralphie's Horn");
  addCardArray(weapon, 2, "CSCI 2270 Midterm 2");
  addCardArray(weapon, 3, "Dean's List");
  addCardArray(weapon, 4, "Flu from the Dorms");
  addCardArray(weapon, 5, "Freshmen Ego");

}

void ClueCard::fillInSuspects(){
  addCardArray(suspect, 6, "Ralphie");
  addCardArray(suspect, 7, "Chip the Buffalo");
  addCardArray(suspect, 8, "Mr. Gold");
  addCardArray(suspect, 9, "Ms. Black");
  addCardArray(suspect, 10, "Prashil");
  addCardArray(suspect, 11, "Tanvi");

}

void ClueCard::fillInRooms(){
  addCardArray(room, 12, "C4C Food");
  addCardArray(room, 13, "Ralphie's Horn");
  addCardArray(room, 14, "CSCI 2270 Midterm 2");
  addCardArray(room, 15, "Dean's List");
  addCardArray(room, 16, "Flu from the Dorms");
  addCardArray(room, 17, "Freshmen Ego");

}

void ClueCard::printArray(){
    for (int i = 0; i < 6; i++){
        cout << weapon[i].key << ":" << weapon[i].name << endl;
    }
}

void deleteElement(Card cards[], int key, int size){
  n = size;
  for (int i = 0; i < n; i++){
    if (cards[i].key == key){
      for (int j = i; j < n-1; j++){
        cards[j] = cards[j+1];
      }
      break;
    }
  }
}

void shuffleArray(Card cards[]){
  for (int i=0; i < 5; i++){
    int r = i + (rand() % (5 - i))
    int temp = cards[i]; cards[i] = cards[r]; cards[r] = temp; // fisher-yates algorithm was the best to use
  }
}

void ClueCard::shuffleCards(){
    srand(time(0));
    int w = rand() % 5;
    // use rand function to get random index from 0 -5
    envelope.insertItem(weapon[r].key, weapon[r].name);
    // add card to envelope: envelope.insertItem(cards[i].key, cards[i].name)
    deleteElement(weapon, weapon[r].key, 6);
    int s = rand() % 5;
    envelope.insertItem(suspect[s].key, weapon[s].name);
    deleteElement(suspect, suspect[r].key, 6);

    int a = rand() % 5;
    envelope.insertItem(room[a].key, room[a].name);
    deleteElement(room, room[r].key, 6);

    // delete card at index from array
    shuffleArray(weapon);
    shuffleArray(suspect);
    shuffleArray(room);
}

// May not need this function since all of the cards are in one hash table
// void ClueCard::combineCards(){
//
// }

void ClueCard::distrubuteCards(){
  // distrubute Cards from array of cards to individual player hash tables
  // merge arrays into one array
  // create 3 for loops
  for (int i = 0; i < 15; i + 3){
    // create pointer and add pointer to card at index to hash table
    // pointer is card struct: Card* card = new Card;
    // card = weapon[i];
    //insertItem(card->key, card->name)
  }

}

// string ClueCard::getCardKey(){
//
// }
//
// string ClueCard::getCardName(){
//
// }

string ClueCard::revealCard(){
  // choose card to show card to show player
  // insert card into player's hashtable
}

int main(){
    ClueCard cards;
    cards.fillInWeapons();
    cards.printArray();
    shuffleCards();
}

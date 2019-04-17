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

void ClueCard::shuffleCards(){
    srand(time(0));
    int r = rand() % 5;
    // use rand function to get random index from 0 -5
    envelope.insertItem()
    // add card to envelope: envelope.insertItem(cards[i].getKey, cards[i])
    // delete card at index from array

  // srand(time(0))
  // n = size of array
  // for (int i=0; i < n; i++){
  //   int r = i + (rand() % (15 - i))
  //   int temp = card[i]; card[i] = card[r]; card[r] = temp;
  // }
}

// May not need this function since all of the cards are in one hash table
// void ClueCard::combineCards(){
//
// }

void ClueCard::distrubuteCards(){
  // distrubute Cards from array of cards to individual player hash tables
}

string ClueCard::getCardKey(){

}

string ClueCard::getCardName(){

}

string ClueCard::revealCard(){
  // choose card to show card to show player
  // insert card into player's hashtable
}

int main(){
//     ClueCard cards;
//     cards.fillInWeapons();
//     cards.printArray();
}

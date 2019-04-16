#include <iostream>

using namespace std;

void ClueCard::shuffleCards(){
  // traverse through main hash table
  // add each element to a new array containing all cards
  // shuffle cards in array

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

string ClueCard::getCardType(){

}

string ClueCard::getCardName(){

}

string ClueCard::revealCard(){
  // choose card to show card to show player
  // insert card into player's hashtable
}

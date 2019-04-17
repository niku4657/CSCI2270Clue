#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

class Player
{
  private:
    HashTable *aTable;

  public:
    //Constructor
    Player();
    //Choose from menu to roll, suggest, and make final accusation.
    void ChooseTurn();
    //Roll Function
    int Dice();
    //Print out Cards
    void printCards();
    //Suggest Function
    void Suggest();
    //Final Accusation
    void FinalAccusation();
};

#endif

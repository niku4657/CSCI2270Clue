#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <cstring>
#include <iostream>
#include <string>
#include "HashTable.hpp"
using namespace std;

class Player
{
  public:
    HashTable *aTable;
    HashTable *pTable;

    //Constructor
    Player();
    //Choose from menu to roll, suggest, and make final accusation.
    string ChooseTurn();
    //Roll Function
    int Dice();
    //Print out Cards
    void printCards();
    //Suggest Function
    string Suggest(int roll);
    //Final Accusation
    string FinalAccusation();
};

#endif

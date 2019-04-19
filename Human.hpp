#ifndef HUMAN_HPP
#define HUMAN_HPP
#include <cstring>
#include <iostream>
#include <string>
#include "Player.hpp"
using namespace std;

class Human : public Player
{
  public:
    HashTable *aTable;
    HashTable *pTable;
    //Constructor
    Human();
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

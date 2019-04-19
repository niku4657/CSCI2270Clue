#ifndef COMPUTER_HPP
#define COMPUTER_HPP
#include <cstring>
#include <iostream>
#include <string>
#include "Player.hpp"
#include "HashTable.hpp"
using namespace std;

class Computer : public Player
{
  public:
    HashTable *aTable;
    HashTable *pTable;
    //Constructor
    Computer();
    //Choose from menu to roll, suggest, and make final accusation.
    string ChooseTurn();
    //Roll Function
    int Dice();
    //Print out Cards
    void printCards();
    //Suspect Helper
    string suspectHelper();
    //Weapon Helper
    string weaponHelper();
    //Suggest Function
    string Suggest(int roll);
    //Final Accusation
    string FinalAccusation();

};
#endif

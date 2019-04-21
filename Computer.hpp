#ifndef COMPUTER_HPP
#define COMPUTER_HPP
#include <cstring>
#include <iostream>
#include <string>
#include "HashTable.hpp"
using namespace std;

class Computer
{
  public:
    HashTable *aTable = new HashTable;
    HashTable *pTable = new HashTable;
    //Constructor
    Computer();
    //Helper to choose to make final accusation.
    bool canMakeFinal();
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
    //Final Weapon Helper Function
    string weaponFinalHelper();
    //Final Suspect Helper Function
    string suspectFinalHelper();
    //Final Room Helper Function
    string roomFinalHelper();
    //Final Accusation
    string FinalAccusation();
    //Reveal Card
    Card* RevealCard(string weapon, string suspect, string room);

};
#endif

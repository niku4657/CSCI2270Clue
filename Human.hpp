#ifndef HUMAN_HPP
#define HUMAN_HPP
#include <cstring>
#include <iostream>
#include <string>
#include "HashTable.hpp"
using namespace std;

class Human
{
  public:
    HashTable *aTable = new HashTable;
    HashTable *pTable = new HashTable;
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
    //Reveal Card
    Card* RevealCard(string weapon, string suspect, string room);
};

#endif

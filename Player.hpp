#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <cstring>
#include <iostream>
#include <string>
#include "HashTable.hpp"
using namespace std;

class Player
{
  private:
    HashTable *aTable;

  public:
    //Constructor
    Player();
    //Choose from menu to roll, suggest, and make final accusation.
    int ChooseTurn(HashTable h);
    //Roll Function
    int Dice();
    //Print out Cards
    void printCards();
    //Suggest Function
    void Suggest(int roll);
    //Helper for Final Accuation
    bool checkEnvelope(string weapon, string suspect, string room);
    //Final Accusation
    void FinalAccusation(HashTable h);
    //Reveal a Card
    string revealCard(string weapon, string suspect, string room);
};

#endif

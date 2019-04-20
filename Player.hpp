#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <cstring>
#include <iostream>
#include <string>
#include "HashTable.hpp"
#include "Human.hpp"
#include "Computer.hpp"
using namespace std;

class Player
{
  public:
    Human h;
    Computer c;
    string name;
    string type;
    //Constructor
    Player();
    //A function to addCards into aTable based on player type...
    void addCard(int key, string name);
    //A function to addCards into pTable based on player type...
    void addCardToP(int key, string name);
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

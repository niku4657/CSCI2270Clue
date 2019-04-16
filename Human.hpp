#ifndef HUMAN_HPP
#define HUMAN_HPP
#include <cstring>
#include <iostream>
#include <string>
#include "Player.hpp"
using namespace std;

class Human
{
  private:
    HashTable *table

  public:
    Human();
    //The human chooses from the menu options of Turn from player class.
    void AcceptTurn();
    //Gotta boogey
    void ChooseMove();
    //Cin all y'all accusations...
    void Suggest(bool final);
    //Call the suggest function from this function with a bool of true.
    void FinalAccusation();

};

#endif

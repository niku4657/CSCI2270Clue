#ifndef COMPUTER_HPP
#define COMPUTER_HPP
#include <cstring>
#include <iostream>
#include <string>
#include "Player.hpp"
using namespace std;

class Computer
{
  private:
    HashTable *cTable

  public:
    Computer();
    //The computer is going to randomly pick an option from Turn function.
    void RandomTurn();
    //Randomly suggest dummies.
    void RandomSuggest(bool final);
    //If ya meet a certain criteria, ye shall accuse.
    void FinalAccusation();

};

#endif

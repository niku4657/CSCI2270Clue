#ifndef COMPUTRE_HPP
#define COMPUTRE_HPP
#include <cstring>
#include <iostream>
#include <string>
#include "Player.hpp"
using namespace std;

class Computre
{
  private:
    HashTable *cTable

  public:
    Computre();
    //The computer is going to randomly pick an option from Turn function.
    void RandomTurn();
    //Calculatedly moooovvvveeeeeeeee
    void RandomMove();
    //Randomly suggest dummies.
    void RandomSuggest(bool final);
    //If ya meet a certain criteria, ye shall accuse.
    void FinalAccusation();

};

#endif

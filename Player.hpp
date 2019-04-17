#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

class Player
{
  private:
    HashTable *aTable;

  public:
    Player();
    //The menu to roll, suggest, and make final accusation.
    void Turn();
    //Roll Function
    int Dice();

};

#endif

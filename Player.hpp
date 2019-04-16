#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

class Player
{
  private:
    HashTable *Player1;
    HashTable *Player2;
    HashTable *Player3;

  public:
    Player();
    //The menu to roll, suggest, and make final accusation.
    void Turn();
    //Roll Function
    int Dice();

};

#endif

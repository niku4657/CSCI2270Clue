#include <iostream>
#include "Player.hpp"
#include "Human.hpp"
#include "Computer.hpp"

using namespace std;


Player::Player()
{
  //Empty.
}

void Player::Turn()
{
  cout << "Main Menu" << endl;
  cout << "1. Roll" << endl;
  cout << "2. Suggest" << endl;
  cout << "3. Final Accusation" << endl;
}

int Player::Dice()
{
  int roll;
  roll = rand() % 7;

  cout << "You rolled a " << roll << endl;
}

void Player::printCards()
{
  cout << "YOUR CARDS" << endl;
  aTable.printTable();
}

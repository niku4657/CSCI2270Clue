#include <iostream>
#include "Player.hpp"
using namespace std;

Player::Player()
{
  //Leave empty.
}

void Player::ChooseTurn()
{
  //Leave empty.
}

int Player::Dice()
{
	return random() % 6 + 1; //Random from 1 to 6 is returned.
}

void Player::printCards()
{
  //Leave empty.
}

void Player::Suggest()
{
  //Leave empty.
}

void Player::FinalAccusation()
{
  //Leave empty.
}

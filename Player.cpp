#include <iostream>
#include "Player.hpp"
using namespace std;

Player::Player()
{
  //Leave empty.
}

int Player::ChooseTurn(HashTable h)
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

bool Player::checkEnvelope(string weapon, string suspect, string room, HashTable h)
{
	Card *w = h.searchItem(0, weapon);
	Card *s = h.searchItem(6, suspect);
	Card *r = h.searchItem(12, room);

	if(w == NULL || s == NULL || r == NULL)
	{
		return false;
	}

	if(w != NULL && s != NULL && r != NULL)
	{
		return true;
	}
}

void Player::FinalAccusation()
{
  //Leave empty.
}

string Player::revealCard(string weapon, string suspect, string room)
{
	//Leave empty.
}

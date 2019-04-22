#include <iostream>
#include "Player.hpp"
using namespace std;

Player::Player()
{
  //Leave empty.
}

void Player::addCard(int key, string name)
{
  if(type == "Human")
  {
    h.aTable -> insertItem(key, name);
  }
  else
  {
    c.aTable -> insertItem(key, name);
  }
}

void Player::addCardToP(int key, string name)
{
  if(type == "Human")
  {
    h.pTable -> insertItem(key, name);
  }
  else
  {
    c.pTable -> insertItem(key, name);
  }
}

string Player::ChooseTurn()
{
  if(type == "Human")
  {
    return h.ChooseTurn();
  }
  else
  {
    return c.ChooseTurn();
  }
}

int Player::Dice()
{
  if(type == "Human")
  {
    return h.Dice();
  }
  else
  {
    return c.Dice();
  }
}

void Player::printCards()
{
  if(type == "Human")
  {
    h.printCards();
  }
  else
  {
    c.printCards();
  }
}

string Player::Suggest(int roll)
{
  if(type == "Human")
  {
    return h.Suggest(roll);
  }
  else
  {
    return c.Suggest(roll);
  }
}

string Player::FinalAccusation()
{
  if(type == "Human")
  {
    return h.FinalAccusation();
  }
  else
  {
    return c.FinalAccusation();
  }
}

Card* Player::RevealCard(string weapon, string suspect, string room)
{
  if(type == "Human")
  {
    return h.RevealCard(weapon, suspect, room);
  }
  else
  {
    return c.RevealCard(weapon, suspect, room);
  }
}

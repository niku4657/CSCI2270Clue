#include <iostream>
#include <string>
#include "Game.hpp"
using namespace std;

void Game::distributeCards(){
  // distribute Cards from array of cards to individual player hash tables
  // merge arrays into one array
  cc.mergeArrays();
  // create 3 for loops
  for (int i = 0; i < 15; i + 2){
    Card* card = new Card;
    card = cc.allCards[i];
    players[0].aTable.insertItem(card->key, card->name);
  }
  for (int i = 1; i < 15; i + 2){
    Card* nextCard = new Card;
    card = cc.allCards[i];
    players[1].aTable.insertItem(card->key, card->name);
  }
  //Use cc.allCards[] and distribute into players' hashtables using players[]!!
}

void Game::duplicateCard(Card* card, Player p)
{
  p.aTable.insertItem(card->key, card->name);
}

void Game::initializePlayersArray()
{
  players[0] = new Human;
  players[1] = new Computer;
}

Card* humanRevealCard(string weapon, string suspect, string room)
{
  string card = "";
  Card *w = players[1].oTable.searchItem(0, weapon);
  Card *s = players[1].oTable.searchItem(6, suspect);
  Card *r = players[1].oTable.searchItem(12, room);

	if(w == NULL && s == NULL && r == NULL)
	{
		cout << "You have no cards to dispute that suggestion." << endl;
	}

	if(w != NULL || s != NULL || r != NULL)
	{
		cout << "Please choose a card to dispute the suggestion:" << endl;

    if(w != NULL)
    {
      cout << w -> name << endl;
    }

    if(s != NULL)
    {
      cout << s -> name << endl;
    }

    if(r != NULL)
    {
      cout << r -> name << endl;
    }

    getline(cin, card);

    if(card == w -> name)
    {
      return w;
    }
    else if(card == s -> name)
    {
      return s;
    }
    else
    {
      return r;
    }
	}

  return NULL;
}

Card* computerRevealCard(string weapon, string suspect, string room)
{
  int randReveal;
  Card *w = players[0].oTable.searchItem(0, weapon);
  Card *s = players[0].oTable.searchItem(6, suspect);
  Card *r = players[0].oTable.searchItem(12, room);

	if(w == NULL && s == NULL && r == NULL)
	{
    cout << "The computer has no cards that dispute the suggestion" << endl;
    return "";
	}

	if(w != NULL || s != NULL || r != NULL)
	{
    if (w != NULL)
    {
      if(s != NULL && r != NULL)
      {
        //Case of computer having all cards.
        randReveal = rand() % 3 + 1; //computer is choosing a card to reveal at random

        if (randReveal == 1)
        {
          return w;
        }
        else if (randReveal == 2)
        {
          return s;
        }
        else if (randReveal == 3)
        {
          return r;
        }
      }
      else if(s != NULL && r == NULL)
      {
        //Case of computer having two cards.
        randReveal = rand() % 2 + 1;

        if (randReveal == 1)
        {
          return w;
        }
        else if (randReveal == 2)
        {
          return s;
        }
      }
      else if(s == NULL && r != NULL)
      {
        //Case of computer having two cards.
        randReveal = rand() % 2 + 1;

        if (randReveal == 1)
        {
          return w;
        }
        else if (randReveal == 2)
        {
          return r;
        }
      }
      else
      {
        //Case of computer having one card.
        return w;
      }
    }
    if (s != NULL)
    {
      if(w != NULL && r != NULL)
      {
        //Case of computer having all cards.
        randReveal = rand() % 3 + 1; //computer is choosing a card to reveal at random

        if (randReveal == 1)
        {
          return s;
        }
        else if (randReveal == 2)
        {
          return w;
        }
        else if (randReveal == 3)
        {
          return r;
        }
      }
      else if(w != NULL && r == NULL)
      {
        //Case of computer having two cards.
        randReveal = rand() % 2 + 1;

        if (randReveal == 1)
        {
          return s;
        }
        else if (randReveal == 2)
        {
          return w;
        }
      }
      else if(w == NULL && r != NULL)
      {
        //Case of computer having two cards.
        randReveal = rand() % 2 + 1;

        if (randReveal == 1)
        {
          return s;
        }
        else if (randReveal == 2)
        {
          return r;
        }
      }
      else
      {
        //Case of computer having one card.
        return s;
      }
    }
    if (r != NULL)
    {
      if(w != NULL && s != NULL)
      {
        //Case of computer having all cards.
        randReveal = rand() % 3 + 1; //computer is choosing a card to reveal at random

        if (randReveal == 1)
        {
          return r;
        }
        else if (randReveal == 2)
        {
          return w;
        }
        else if (randReveal == 3)
        {
          return s;
        }
      }
      else if(w != NULL && s == NULL)
      {
        //Case of computer having two cards.
        randReveal = rand() % 2 + 1;

        if (randReveal == 1)
        {
          return r;
        }
        else if (randReveal == 2)
        {
          return w;
        }
      }
      else if(w == NULL && s != NULL)
      {
        //Case of computer having two cards.
        randReveal = rand() % 2 + 1;

        if (randReveal == 1)
        {
          return r;
        }
        else if (randReveal == 2)
        {
          return s;
        }
      }
      else
      {
        //Case of computer having one card.
        return r;
      }
    }
	}
}

void startGame()
{
  //Game Setup
  ClueCard cc;
  bool isRunning = true;
  //int humanTurnOut;
  string humanTurnOut;
  string gameSuggest = "Suggest";
  string gameAccuse = "Final Accusation";
  //int computerTurnOut;
  string computerTurnOut;

  cc.initializePlayersArray();

  cc.fillInWeapons();
  cc.fillInSuspects();
  cc.fillInRooms();
  cc.shuffleCards();
  cc.distributeCards();

  //Game Start
  cout << "Game Intro" << endl;
  //int moveToNext
  while(isRunning)
  {
    humanTurnOut = cc.players[0].ChooseTurn(players[1].aTable);

    if(humanTurnOut.find(gameSuggest) != npos) //npos means greatest length of string
    {
      //Suggestion
      //Call human suggestion function - which returns w s r
      //create split function that will split the long string
      //call computer revealCard function
      computerTurnOut = cc.players[1].ChooseTurn(players[0].aTable);//switch players
    }
    else if(humanTurnOut.find(gameAccuse) != npos)
    {
      //Final Accusation
      isRunning = false;
    }
    else if(humanTurnOut == quitTurn)
    {
      //Quit Turn
      computerTurnOut = cc.players[1].ChooseTurn(players[0].aTable);
    }
    else
    {
      //Quit Game
      isRunning = false;
    }
  }
}

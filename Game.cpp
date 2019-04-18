#include <iostream>
#include "Game.hpp"
using namespace std;

void Game::distributeCards(){
  // distribute Cards from array of cards to individual player hash tables
  // merge arrays into one array
  cc.mergeArrays();
  // create 3 for loops
  for (int i = 0; i < 15; i + 3){
    Card* card = new Card;
    card = cc.allCards[i];
    players[0].aTable.insertItem(card->key, card->name);
  }
  for (int i = 1; i < 15; i + 3){
    Card* nextCard = new Card;
    card = cc.allCards[i];
    players[1].aTable.insertItem(card->key, card->name);
  }
  for (int i = 2; i < 15; i + 3){
    Card* thirdCard = new Card;
    card = cc.allCards[i];
    player[2].aTable.insertItem(card->key, card->name);
  }
  //Use cc.allCards[] and distribute into players' hashtables using players[]!!
}

void Game::duplicateCard(int key, string name, Player p)
{
  p.aTable.insertItem(key, name);
}

void Game::initializePlayersArray()
{
  players[0] = new Human;
  players[1] = new Computer;
  players[2] = new Computer;
}

void startGame()
{
  //Game Setup
  ClueCard cc;
  bool isRunning = true;
  int humanTurnOut;
  int computerTurnOut;

  cc.initializePlayersArray();

  cc.fillInWeapons();
  cc.fillInSuspects();
  cc.fillInRooms();
  cc.shuffleCards();
  cc.distrubuteCards();

  //Game Start
  cout << "Game Intro" << endl;
int moveToNext
  while(isRunning)
  {
    humanTurnOut = cc.players[0].ChooseTurn(players[1].aTable);

    if(humanTurnOut == 1)
    {
      //Suggestion
      computerTurnOut = cc.players[1].ChooseTurn(players[0].aTable);
    }
    else if(humanTurnOut == 2)
    {
      //Final Accusation
      isRunning = false;
    }
    else if(humanTurnOut == 3)
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

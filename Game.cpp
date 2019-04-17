#include <iostream>
#include "ClueCard.hpp"
#include "HashTable.hpp"
#include "Player.hpp"
#include "Human.hpp"
#include "Computer.hpp"
using namespace std;

int main()
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

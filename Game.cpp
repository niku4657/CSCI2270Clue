#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>
#include "Game.hpp"
#include "Computer.hpp"
#include "Player.hpp"
#include "Human.hpp"
#include "HashTable.hpp"
#include "ClueCard.hpp"
#include <Windows.h>
/* srand, rand */
#include <time.h>       /* time */



#include<conio.h>
using namespace std;

Game::Game()
{
  //Leave empty.
}

Game::~Game()
{
  //Leave empty.
}

void Game::initializePlayersArray()
{
  players[0].name = "h1";
  players[0].type = "Human";

  players[1].name = "h2";
  players[1].type = "Human";

  players[2].name = "h3";
  players[2].type = "Human";
}

void Game::distributeCards()
{
  cc.mergeArrays();
  Card* card = new Card;

  for(int i = 0; i < 15; i = i + 3)
  {
    card = &(cc.allCards[i]);
    players[0].addCard(card -> key, card -> name);
  }

  for (int i = 1; i < 15; i = i + 3)
  {
    card = &(cc.allCards[i]);
    players[1].addCard(card -> key, card -> name);
  }

  for(int i = 2; i < 15; i = i + 3)
  {
    card = &(cc.allCards[i]);
    players[2].addCard(card -> key, card -> name);
  }
}

int split(string str, char c, string array[], int size)
{
    if(str.length() == 0)
    {
         return 0;
    }

    string word = "";
    int count = 0;
    str = str + c;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == c)
        {
            if (word.length() == 0)
                continue;
            array[count++] = word;
            word = "";
        }
        else
        {
            word = word + str[i];
        }
    }

    return count;
}

void Game::startGame()
{
  srand (time(NULL));
  //Game Setup
  bool isRunning = true;
  string arr[4];
  string turnOut;
  string gameSuggest = "Suggest";
  string gameAccuse = "Final Accusation";
  Card *c;
  Card *c2;
  int currTurn = 0;
  int numOfPlayers = 3;

  initializePlayersArray();
  cc.fillInWeapons();
  cc.fillInSuspects();
  cc.fillInRooms();

  cc.shuffleCards();

  distributeCards();

  //Game Start
  cout << "                               Welcome to the Game of Clue!" << endl;
  cout << "--------------------------------------------------------------------------------------------------" << endl;
  cout << " Somewhere on the vast campus of University of Colorado Boulder, a horrible crime was committed." << endl << endl;
  cout << "         The suspects of this crime could be anyone, anywhere, or anything." << endl << endl;
  cout << "     It's your job to journey through the campus and use clues to determine which suspects" << endl;
  cout << "                  are eliminated and which are the potential criminals." << endl << endl;
  cout << "             By playing against the computer, you will solve this murder mystery" << endl;
  cout << "             by making suggestions along the way to help your elimination, and make" << endl;
  cout << "                  a final accusation if you think you have uncovered the culprit." << endl << endl;
  cout << "                               It's time to start the game... " << endl;
  cout << "--------------------------------------------------------------------------------------------------" << endl;
  cout << "                        Good Luck, and may the best detective win!" << endl;

  while(isRunning)
  {
    currTurn = currTurn % numOfPlayers;
    cout << "It is now " << players[currTurn].name << "'s turn." << endl << endl;
    turnOut = players[currTurn].ChooseTurn();

    if(turnOut.find(gameSuggest) != string::npos) //npos means greatest length of string
    {
      //Suggestion
      if(turnOut != "Suggest,Done")
      {
        cout<<turnOut<<endl;
        split(turnOut, ',', arr, 4);
        vector<Card*> reveal;
        for(int i = 0; i < 3; i++)
        {
          if(i != currTurn)
          {
            cout<<"******"<<arr[1]<<endl;

              cout<<"****"<<arr[2]<<endl;

                cout<<"***"<<arr[3]<<endl;
            Card* c = players[i].RevealCard(arr[1], arr[2], arr[3]);
            if(c != NULL)
            {
              reveal.push_back(c);
            }
          }
        }

        for(int i = 0; i < reveal.size(); i++)
        {
          players[i].addCardToP(reveal[i] -> key, reveal[i] -> name);
        }
      }

      //Switch Players
      currTurn++;
    }
    else if(turnOut.find(gameAccuse) != string::npos)
    {
      //Final Accusation
      split(turnOut, ',', arr, 4);

      if(cc.checkEnvelope(arr[1], arr[2], arr[3]))
      {
        cout << "Congratulations, you have successfully solved the mystery! Great job detective!" << endl;
      }
      else
      {
        cout << "Sorry! You have not accurately uncovered the suspects of this mystery. Better luck next time!" << endl;
      }

      cout << "The correct details to this mystery were: " << endl;

      cc.envelope -> printTable();

      isRunning = false;
    }
    else if(turnOut == "Quit Turn")
    {
      //Quit Turn
      cout << "The turn was forfeited." << endl;
      currTurn++;
    }
    else if(turnOut == "Quit Game")
    {
      //Quit Game
      cout << "You have quit the game." << endl;
      isRunning = false;
    }

    //Sleep Time
    Sleep(5000);
    //Clear The Screen
    //system("cls");
  }

  cout << "The game is over!" << endl;
}

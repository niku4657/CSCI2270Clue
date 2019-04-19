#include <iostream>
#include <string>
#include "Game.hpp"
#include "Computer.hpp"
#include "Player.hpp"
#include "Human.hpp"
#include "HashTable.hpp"
#include "ClueCard.hpp"
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
  players[0] = new Human();
  players[1] = new Computer();
  players[2] = new Computer();
}

void Game::distributeCards()
{
  cc.mergeArrays();
  Card* card = new Card;
  for(int i = 0; i < 15; i + 3)
  {
    card = &(cc.allCards[i]);
    players[0] -> aTable -> insertItem(card -> key, card -> name);
  }

  for (int i = 1; i < 15; i + 3)
  {
    card = &(cc.allCards[i]);
    players[1] -> aTable -> insertItem(card -> key, card -> name);
  }

  for(int i = 2; i < 15; i + 3)
  {
    card = &(cc.allCards[i]);
    players[1] -> aTable -> insertItem(card -> key, card -> name);
  }
}

void Game::duplicateCard(Card* card, Player* p)
{
  p -> pTable -> insertItem(card -> key, card -> name);
}

Card* Game::humanRevealCard(string weapon, string suspect, string room, int num)
{
  string card = "";
  Card *w = players[num] -> pTable -> searchItem(0, weapon);
  Card *s = players[num] -> pTable -> searchItem(6, suspect);
  Card *r = players[num] -> pTable -> searchItem(12, room);

	if(w == NULL && s == NULL && r == NULL)
	{
		cout << "You have no cards to dispute the computer's suggestion." << endl;
	}

	if(w != NULL || s != NULL || r != NULL)
	{
		cout << "Please choose a card to dispute the computer's suggestion:" << endl;

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

Card* Game::computerRevealCard(string weapon, string suspect, string room, int num)
{
  int randReveal;
  Card *w = players[num] -> pTable -> searchItem(0, weapon);
  Card *s = players[num] -> pTable -> searchItem(6, suspect);
  Card *r = players[num] -> pTable -> searchItem(12, room);

	if(w == NULL && s == NULL && r == NULL)
	{
    cout << "The computer has no cards that dispute the human's suggestion." << endl;
    return NULL;
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
  //Game Setup
  bool isRunning = true;
  string arr[4];
  string humanTurnOut;
  string gameSuggest = "Suggest";
  string gameAccuse = "Final Accusation";
  string computerTurnOut;
  Card *c = new Card;
  Card *c2 = new Card;
  int currTurn = 0;
  int numOfPlayers = 3;

  initializePlayersArray();
  cc.fillInWeapons();
  cc.fillInSuspects();
  cc.fillInRooms();
  cc.shuffleCards();
  distributeCards();

  //Game Start
  cout << "                  Welcome to the Game of Clue!" << endl;
  cout << "---------------------------------------------------------------" << endl;
  cout << "Somewhere on the vast campus of University of Colorado Boulder, a horrible crime was committed." << endl;
  cout << "The suspects of this crime could be anyone, anywhere, or anything." << endl;
  cout << "It's your job to journey through the campus and use clues to determine which suspects";
  cout << " are eliminated and which are the potential criminals." << endl;
  cout << "By playing against the computer, you will solve this murder mystery by making suggestions along";
  cout << " the way to help your elimination, and make a final accusation if you think you have uncovered the culprit." << endl;
  cout << "                  It's time to start the game... " << endl;
  cout << "---------------------------------------------------------------" << endl;
  cout << "         Good Luck, and may the best detective win!" << endl;

  while(isRunning)
  {
    currTurn = currTurn % numOfPlayers;
    humanTurnOut = players[currTurn] -> ChooseTurn();

    if(humanTurnOut.find(gameSuggest) != string::npos) //npos means greatest length of string
    {
      //Suggestion
      split(humanTurnOut, ',', arr, 4);
      if(currTurn == 0)
      {
        c = computerRevealCard(arr[1], arr[2], arr[3], currTurn++);
        c2 = computerRevealCard(arr[1], arr[2], arr[3], currTurn + 2);
      }
      else if(currTurn == 1)
      {
        c2 = computerRevealCard(arr[1], arr[2], arr[3], currTurn++);
        c = humanRevealCard(arr[1], arr[2], arr[3], currTurn + 2);
      }
      else
      {
        c = humanRevealCard(arr[1], arr[2], arr[3], currTurn++);
        c2 = computerRevealCard(arr[1], arr[2], arr[3], currTurn + 2);
      }

      duplicateCard(c, players[currTurn]);
      duplicateCard(c2, players[currTurn]);

      //Switch Players
      currTurn++;
      computerTurnOut = players[currTurn] -> ChooseTurn();
    }
    else if(humanTurnOut.find(gameAccuse) != string::npos)
    {
      //Final Accusation
      split(humanTurnOut, ',', arr, 4);

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
    else if(humanTurnOut == "Quit Turn")
    {
      //Quit Turn
      currTurn++;
      computerTurnOut = players[currTurn] -> ChooseTurn(); //switch players
    }
    else
    {
      //Quit Game
      cout << "You have quit the game." << endl;
      isRunning = false;
    }
  }

  cout << "THE MURDERER GOT TO YOU." << endl;
}

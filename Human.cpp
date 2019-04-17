#include <iostream>
#include "Human.hpp"
using namespace std;

int Human::ChooseTurn(HashTable h)
{
  string option;
  int roll = Dice();
  cout << "You rolled a " << roll << endl;
  cout << "Main Menu" << endl;
  cout << "1. Suggest" << endl;
  cout << "2. Final Accusation" << endl;
  cout << "3. Quit Turn" << endl;
  cout << "4. Quit Game" << endl;

  cout << "Please pick one of the options above." << endl;
  getline(cin, option);

  if (option == 1)
  {
    Suggest(roll, h);
    return 1;
  }
  else if (option == 2)
  {
    FinalAccusation(h);
    return 2;
  }
  else if (option == 3)
  {
    cout << "You have quit your turn." << endl;
    return 3;
  }
  else if(option == 4)
  {
    cout << "You have quit the game." << endl;
    return 4;;
  }

  return 0;
}

void Human::printCards()
{
  cout << "YOUR CARDS" << endl;
  hTable.printTable();
}

void Human::Suggest(int roll, HashTable h)
{
  string room;
  string suspect;
  string weapon;

  if (roll == 1 || roll == 3 || roll == 5)
  {
    cout << "You can enter a room, choose from the following:"
    cout << "UMC" << endl;
    cout << "Farrand Field" << endl;
    cout << "CSEL" << endl;
    cout << "Kittredge Central" << endl;
    cout << "Folsom Field" << endl;
    cout << "C4C" << endl;
    getline(cin, room);

    cout << "You have made it into the " << room << endl;
    cout << "You can now make a suggestion of who you think committed the murder" << endl;

    cout << "Your Suggestion:" << endl;
    cout << "Room: " << room << endl;

    cout << "Suspect";
    getline(cin, suspect);
    cout << endl;

    cout << "Weapon";
    getline(cin, weapon);
    cout << endl;

    string eliminated = revealCard(weapon, suspect, room, h);
    hTable.insertItem(0, eliminated);
  }
  else
  {
    cout << "You can't enter a room, it is now the computer's turn.";
    cout << endl;
  }
}

void Human::FinalAccusation(HashTable h)
{
  string room;
  string suspect;
  string weapon;

  cout << "Your Final Accusation:" << endl;

  cout << "Weapon";
  getline(cin, weapon);
  cout << endl;

  cout << "Suspect";
  getline(cin, suspect);
  cout << endl;

  cout << "Room:"
  getline(cin, room);
  cout << endl;

  if(checkEnvelope(weapon, suspect, room, h))
  {
    cout << "Congratulations you won the game!!!!" << endl;
  }
  else
  {
    cout << "You lost the game..." << endl;
  }

  cout << "The correct answer is:" << endl;
  h.printTable();
  return;
}

string Human::revealCard(string weapon, string suspect, string room, HashTable h)
{
  int randReveal;
  Card *w = h.searchItem(0, weapon);
	Card *s = h.searchItem(6, suspect);
	Card *r = h.searchItem(12, room);

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
          return w->name;
        }
        else if (randReveal == 2)
        {
          return s->name;
        }
        else if (randReveal == 3)
        {
          return r->name;
        }
      }
      else if(s != NULL && r == NULL)
      {
        //Case of computer having two cards.
        randReveal = rand() % 2 + 1;

        if (randReveal == 1)
        {
          return w->name;
        }
        else if (randReveal == 2)
        {
          return s->name;
        }
      }
      else if(s == NULL && r != NULL)
      {
        //Case of computer having two cards.
        randReveal = rand() % 2 + 1;

        if (randReveal == 1)
        {
          return w->name;
        }
        else if (randReveal == 2)
        {
          return r->name;
        }
      }
      else
      {
        //Case of computer having one card.
        return w -> name;
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
          return s->name;
        }
        else if (randReveal == 2)
        {
          return w->name;
        }
        else if (randReveal == 3)
        {
          return r->name;
        }
      }
      else if(w != NULL && r == NULL)
      {
        //Case of computer having two cards.
        randReveal = rand() % 2 + 1;

        if (randReveal == 1)
        {
          return s->name;
        }
        else if (randReveal == 2)
        {
          return w->name;
        }
      }
      else if(w == NULL && r != NULL)
      {
        //Case of computer having two cards.
        randReveal = rand() % 2 + 1;

        if (randReveal == 1)
        {
          return s->name;
        }
        else if (randReveal == 2)
        {
          return r->name;
        }
      }
      else
      {
        //Case of computer having one card.
        return s -> name;
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
          return r->name;
        }
        else if (randReveal == 2)
        {
          return w->name;
        }
        else if (randReveal == 3)
        {
          return s->name;
        }
      }
      else if(w != NULL && s == NULL)
      {
        //Case of computer having two cards.
        randReveal = rand() % 2 + 1;

        if (randReveal == 1)
        {
          return r->name;
        }
        else if (randReveal == 2)
        {
          return w->name;
        }
      }
      else if(w == NULL && s != NULL)
      {
        //Case of computer having two cards.
        randReveal = rand() % 2 + 1;

        if (randReveal == 1)
        {
          return r->name;
        }
        else if (randReveal == 2)
        {
          return s->name;
        }
      }
      else
      {
        //Case of computer having one card.
        return r -> name;
      }
    }
	}
}

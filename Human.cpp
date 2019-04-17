#include <iostream>
#include "Human.hpp"
using namespace std;

int Human::ChooseTurn(HashTable h)
{
  string option;
  cout << "Main Menu" << endl;
  cout << "1. Suggest" << endl;
  cout << "2. Final Accusation" << endl;
  cout << "3. Quit Turn" << endl;
  cout << "4. Quit Game" << endl;

  cout << "Please pick one of the options above." << endl;
  getline(cin, option);

  if (option == 1)
  {
    Suggest();
  }
  else if (option == 2)
  {
    FinalAccusation(h);
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

void Human::Suggest(int roll)
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

string Human::revealCard(string weapon, string suspect, string room)
{
  Card *w = hTable.searchItem(0, weapon);
  Card *s = hTable.searchItem(6, suspect);
  Card *r = hTable.searchItem(12, room);
  string card = "";

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
	}

  return card;
}

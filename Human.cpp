#include <iostream>
#include "Human.hpp"
#include <vector>
using namespace std;

Human::Human()
{
  //Leave empty.
}

void showAllCards(){

  cout << "Here are all the possible details to the mystery:" << endl << endl;
  cout << "Weapons:" << endl;
  cout << "_________" << endl;
  cout << "C4C Food" << endl;
  cout << "Ralphie's Horn" << endl;
  cout << "CSCI 2270 Midterm 2" << endl;
  cout << "Dean's List" << endl;
  cout << "Flu from the Dorms" << endl;
  cout << "Freshmen Ego" << endl << endl;

  cout << "Suspects:" << endl;
  cout << "_________" << endl;
  cout << "Ralphie" << endl;
  cout << "Chip the Buffalo" << endl;
  cout << "Mr. Gold" << endl;
  cout << "Ms. Black" << endl;
  cout << "Prashil" << endl;
  cout << "Tanvi" << endl << endl;

  cout << "Rooms:" << endl;
  cout << "_________" << endl;
  cout << "UMC" << endl;
  cout << "Farrand Field" << endl;
  cout << "CSEL" << endl;
  cout << "Kittredge" << endl;
  cout << "Folsom Field" << endl;
  cout << "C4C" << endl << endl;
}

string Human::ChooseTurn()
{
  string option;
  string turnResult;
  string quitTurn;
  string quitGame;

  cout << "You will now roll the dice." << endl;
  int roll = Dice();
  cout << "You rolled a " << roll << "!" << endl << endl;

  showAllCards();

  printCards();

  cout << "Main Menu" << endl;
  cout << "--------------------" << endl;
  cout << "1. Suggest" << endl;
  cout << "2. Final Accusation" << endl;
  cout << "3. Quit Turn" << endl;
  cout << "4. Quit Game" << endl << endl;

  cout << "Pick one of the options above." << endl;
  getline(cin, option);
  cout << endl;

  if (option == "1")
  {
    turnResult = Suggest(roll);
    return turnResult;
  }
  else if (option == "2")
  {
    turnResult = FinalAccusation();
    return turnResult;
  }
  else if (option == "3")
  {
    cout << "You have chosen to quit your turn. The computer will now proceed with their turn." << endl;
    quitTurn = "Quit Turn";
    return quitTurn;
  }
  else if(option == "4")
  {
    cout << "You have chosen to quit the game. Goodbye!" << endl;
    quitGame = "Quit Game";
    return quitGame;
  }
}

int Human::Dice()
{
	return rand() % 6 + 1; //Random from 1 to 6 is returned.
}

void Human::printCards()
{
  cout << "YOUR CARDS:" << endl << endl;
  cout << "* Reference these cards to make future suggestions";
  cout << " about what evidence is eliminated and which could be solution to the mystery *" << endl << endl;
  aTable -> printTable();
  cout << "REVEALED CARDS:" << endl << endl;
  pTable -> printTable();
}

string Human::Suggest(int roll)
{
  string room;
  string suspect;
  string weapon;

  if (roll == 1 || roll == 3 || roll == 5)
  {
    cout << "Your roll has landed you in a room! Choose from the following:" << endl;
    cout << "UMC" << endl;
    cout << "Farrand Field" << endl;
    cout << "CSEL" << endl;
    cout << "Kittredge" << endl;
    cout << "Folsom Field" << endl;
    cout << "C4C" << endl << endl;

    getline(cin, room);

    cout << "You have made it into " << room << "." << endl << endl;
    cout << "You can now make a suggestion of who you think committed the murder" << endl;

    cout << "Your Suggestion:" << endl << endl;
    cout << "Room: " << room << endl;

    cout << "Suspect: ";
    getline(cin, suspect);

    cout << "Weapon: ";
    getline(cin, weapon);
    cout << endl;

    string suggestResult = "Suggest," + weapon + "," + suspect + "," + room;

    return suggestResult;
  }
  else
  {
    cout << "Your roll has not landed you in a room, so it is now the next player's turn." << endl << endl;
    return "Suggest,Done";
  }
}

string Human::FinalAccusation()
{
  string room;
  string suspect;
  string weapon;

  cout << "You have chosen to make a final accusation for the remaining suspects." << endl;
  cout << "Choose your suspects wisely! If you are inaccurate, you will lose the game." << endl;
  cout << endl << endl;

  cout << "Your Final Accusation:" << endl;
  cout << "----------------------" << endl;

  cout << "Weapon: ";
  getline(cin, weapon);
  cout << endl;

  cout << "Suspect: ";
  getline(cin, suspect);
  cout << endl;

  cout << "Room: ";
  getline(cin, room);
  cout << endl;

  string finalResult = "Final Accusation," + suspect + "," + room + "," + weapon;

  return finalResult;
}

Card* Human::RevealCard(string weapon, string suspect, string room)
{
  Card* cards[3];
  vector<Card*> notNull;

  cards[0] = aTable -> searchItem(0, weapon);
  cards[1] = aTable -> searchItem(6, suspect);
  cards[2] = aTable -> searchItem(12, room);

  for(int i = 0; i < 3; i++)
  {
    if(cards[i] != NULL)
    {
      notNull.push_back(cards[i]);
    }
  }

	if(notNull.size() == 0)
	{
		cout << "There are no cards to dispute the player's suggestion." << endl;
    return NULL;
  }

  cout << "Please choose a card to dispute the player's suggestion:" << endl;

  for(int i = 0; i < notNull.size(); i++)
  {
    cout << notNull[i] -> name << endl;
  }

  string card;
  getline(cin, card);

  for(int i = 0; i < notNull.size(); i++)
  {
    if(card == notNull[i] -> name)
      return notNull[i];
  }

  cout << "You spelled it incorrectly." << endl;
  return NULL;
}

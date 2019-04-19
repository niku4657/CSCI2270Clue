#include <iostream>
#include "Human.hpp"
using namespace std;

string Human::ChooseTurn()
{
  string option;
  string turnResult;
  string quitTurn;
  string quitGame;
  int roll = Dice();
  cout << "You rolled a " << roll << "!" << endl;
  printCards();
  cout << "Main Menu" << endl;
  cout << "--------------------" << endl;
  cout << "1. Suggest" << endl;
  cout << "2. Final Accusation" << endl;
  cout << "3. Quit Turn" << endl;
  cout << "4. Quit Game" << endl;

  cout << "Pick one of the options above." << endl;
  getline(cin, option);

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
  return "";
}

int Human::Dice()
{
	return rand() % 6 + 1; //Random from 1 to 6 is returned.
}

void Human::printCards()
{
  cout << "YOUR CARDS" << endl;
  cout << "* Reference these cards to make future suggestions";
  cout << " about what evidence is eliminated and which could be solution to the mystery *" << endl;
  aTable -> printTable();
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
    cout << "C4C" << endl;

    getline(cin, room);

    cout << "You have made it into the " << room << "." << endl;
    cout << "You can now make a suggestion of who you think committed the murder" << endl;

    cout << "Your Suggestion:" << endl;
    cout << "Room: " << room << endl;

    cout << "Suspect";
    getline(cin, suspect);
    cout << endl;

    cout << "Weapon";
    getline(cin, weapon);
    cout << endl;

    string suggestResult = "Suggest: " + weapon + ", " + suspect + ", " + room;

    return suggestResult;
  }
  else
  {
    cout << "Your roll has not landed you in a room, so it is now the computer's turn.";
    cout << endl;
    return "";
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

  cout << "Weapon";
  getline(cin, weapon);
  cout << endl;

  cout << "Suspect";
  getline(cin, suspect);
  cout << endl;

  cout << "Room:";
  getline(cin, room);
  cout << endl;

  return "Final Accusation";
}

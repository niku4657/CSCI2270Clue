#include <iostream>
#include "Human.hpp"
using namespace std;

string Human::ChooseTurn()
{
  string option;
  string turnResult;
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
    turnResult = Suggest(roll, h);
    return turnResult;
  }
  else if (option == 2)
  {
    turnResult = FinalAccusation(h);
    return turnResult;
  }
  else if (option == 3)
  {
    cout << "You have quit your turn." << endl;
    return "Quit Turn";
  }
  else if(option == 4)
  {
    cout << "You have quit the game." << endl;
    return "Quit Game";
  }

  return "";
}

void Human::printCards()
{
  cout << "YOUR CARDS" << endl;
  hTable.printTable();
}

string Human::Suggest(int roll)
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

    string suggestResult = weapon + ", " + suspect + ", " + room;

    return suggestResult;
  }
  else
  {
    cout << "You can't enter a room, it is now the computer's turn.";
    cout << endl;
    return "";
  }
}

string Human::FinalAccusation()
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
  return "";
}

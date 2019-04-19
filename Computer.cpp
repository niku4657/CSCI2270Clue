#include <iostream>
#include "Computer.hpp"
#include "HashTable.hpp"
#include "Player.hpp"
using namespace std;

Computer::Computer()
{
  //Leave empty.
}

string Computer::ChooseTurn()
{
  int computerTurn;
  string compResult;
  int roll = Dice();
  cout << "You rolled a " << roll << "!" << endl;
  printCards();
  cout << "Main Menu" << endl;
  cout << "--------------------" << endl;
  cout << "1. Suggest" << endl;
  cout << "2. Final Accusation" << endl;
  cout << "3. Quit Turn" << endl;
  //random function between 1 - 3
  computerTurn = rand() % 4 + 1;

  if (computerTurn == 1)
  {
    compResult = Suggest(roll);
    return compResult;
  }
  else if (computerTurn == 2)
  {
    compResult = FinalAccusation();
    return compResult;
  }
  else if (computerTurn == 3)
  {
    cout << "The computer has quit its turn. It is now the human's turn." << endl; //Switch turn in int main
    return "Quit Turn";
  }
}

int Computer::Dice()
{
	return rand() % 6 + 1; //Random from 1 to 6 is returned.
}

void Computer::printCards(){
  aTable -> printTable();
  pTable -> printTable();
}

string Computer::suspectHelper(){
  int randSuspect;
  string computerSuggestSuspect;
  //rand function between 6 and 11
  randSuspect = rand() % 6 + 6;

  //call search function with that random integer
  Card *temp = aTable -> searchItem(randSuspect);

  if(temp != NULL)
  {
    computerSuggestSuspect = temp->name;
  }

  return computerSuggestSuspect;
}

string Computer::weaponHelper(){
  int randWeapon;
  string computerSuggestWeapon;
  //rand function between 12 and 17
  randWeapon = rand() % 6 + 12;

  //call search function with that random integer
  Card *tempW = aTable -> searchItem(randWeapon);

  if (tempW != NULL)
  {
    computerSuggestWeapon = tempW->name;
  }

  return computerSuggestWeapon;
}

string Computer::Suggest(int roll)
{
  string weapon;
  string suspect;
  string room;
  int computerDice;

  if (roll == 1 || roll == 3 || roll == 5)
  {
    cout << "The computer will now choose a room to go into." << endl;
    cout << "UMC" << endl;
    cout << "Farrand Field" << endl;
    cout << "CSEL" << endl;
    cout << "Kittredge" << endl;
    cout << "Folsom Field" << endl;
    cout << "C4C" << endl;

    computerDice = rand() % 6 + 1;

    switch(computerDice)
    {
      case 1:
        room = "UMC";
      break;

      case 2:
        room = "Farrand Field";
      break;

      case 3:
        room = "CSEL";
      break;

      case 4:
        room = "Kittredge";
      break;

      case 5:
        room = "Folsom Field";
      break;

      case 6:
        room = "C4C";
      break;
    }

    cout << "The computer has made it into the " << room << endl;
    cout << "The computer will now make a suggestion as to who it thinks committed the murder" << endl;

    cout << "Computer's Suggestion:" << endl;
    cout << "Room: " << room << endl;
    suspect = suspectHelper();
    cout << "Suspect: " << suspect << endl;
    weapon = weaponHelper();
    cout << "Weapon: " << weapon << endl;

    string compSuggest = "Suggest: " + weapon + ", " + suspect + ", " + room;

    return compSuggest;
  }
  else
  {
    return "";
  }
}

string finalWeapon()
{
  int computerDice = rand() % 6 + 1;
  string weapon;

  switch(computerDice)
  {
    case 1:
      weapon = "C4C Food";
    break;

    case 2:
      weapon = "Ralphie's Horn";
    break;

    case 3:
      weapon = "CSCI 2270 Midterm 2";
    break;

    case 4:
      weapon = "Dean's List";
    break;

    case 5:
      weapon = "Flu from the Dorms";
    break;

    case 6:
      weapon = "Freshmen Ego";
    break;
  }

  return weapon;
}

string finalSuspect()
{
  int computerDice = rand() % 6 + 1;
  string suspect;

  switch(computerDice)
  {
    case 1:
      suspect = "Ralphie";
    break;

    case 2:
      suspect = "Chip the Buffalo";
    break;

    case 3:
      suspect = "Mr. Gold";
    break;

    case 4:
      suspect = "Ms. Black";
    break;

    case 5:
      suspect = "Prashil";
    break;

    case 6:
      suspect = "Tanvi";
    break;
  }

  return suspect;
}

string finalRoom()
{
  int computerDice = rand() % 6 + 1;
  string room;

  switch(computerDice)
  {
    case 1:
      room = "UMC";
    break;

    case 2:
      room = "Farrand Field";
    break;

    case 3:
      room = "CSEL";
    break;

    case 4:
      room = "Kittredge";
    break;

    case 5:
      room = "Folsom Field";
    break;

    case 6:
      room = "C4C";
    break;
  }

  return room;
}

string Computer::FinalAccusation()
{
  string weapon;
  string suspect;
  string room;
  bool checkWeapon = true;
  bool checkSuspect = true;
  bool checkRoom = true;

  cout << "The computer has made it into the " << room << "." << endl;
  cout << "The computer will now make a final accusation as to who it thinks committed the murder." << endl;

  while(checkWeapon == true)
  {
    weapon = finalWeapon();
    checkWeapon = aTable -> searchItem(0, weapon);

    if(checkWeapon == NULL)
    {
      pTable -> searchItem(0, weapon);
    }
  }

  while(checkSuspect == true)
  {
    suspect = finalSuspect();
    checkWeapon = aTable -> searchItem(6, suspect);

    if(checkWeapon == NULL)
    {
      pTable -> searchItem(6, suspect);
    }
  }

  while(checkWeapon == true)
  {
    room = finalRoom();
    checkWeapon = aTable -> searchItem(12, suspect);

    if(checkWeapon == NULL)
    {
      pTable -> searchItem(12, suspect);
    }
  }

  cout << "Computer's Accusation:" << endl;
  cout << "Room: " << room << endl;
  cout << "Suspect: " << suspect << endl;
  cout << "Weapon: " << weapon << endl;

  string compSuggest = "Final Accusation: " + weapon + ", " + suspect + ", " + room;

  return compSuggest;
}

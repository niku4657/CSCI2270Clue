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
  cout << "Computer's Cards" << endl;
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

string Computer::weaponFinalHelper()
{
  string allWeapons[] = {"C4C Food", "Ralphie's Horn", "CSCI 2270 Midterm 2", "Dean's List", "Flu from the Dorms", "Freshmen Ego"};

  for (int i = 0; i < aTable -> tableSize; i++)
  {
    for (int j = 0; j < 6; j++)
    {
      if (aTable[i].name == allWeapons[j])
      {
        allWeapons[j] == "";
      }
    }
  }

  for (int k = 0; k < pTable -> tableSize; k++)
  {
    for (int n = 0; n < 6; n++)
    {
      if (pTable[k].name == allWeapons[n])
      {
        allWeapons[n] == "";
      }
    }
  }

  for (int x = 0; x < 6; x++)
  {
    if (allWeapons[x] != "")
    {
      return allWeapons[x];
    }
  }
}

string Computer::suspectFinalHelper()
{
  string allSuspects[] = {"Ralphie", "Chip the Buffalo", "Mr. Gold", "Ms. Black", "Prashil", "Tanvi"};

  for (int i = 0; i < aTable -> tableSize; i++)
  {
    for (int j = 0; j < 6; j++)
    {
      if (aTable[i].name == allSuspects[j])
      {
        allSuspects[j] == "";
      }
    }
  }

  for (int k = 0; k < pTable -> tableSize; k++)
  {
    for (int n = 0; n < 6; n++)
    {
      if (pTable[k].name == allSuspects[n])
      {
        allSuspects[n] == "";
      }
    }
  }

  for (int x = 0; x < 6; x++)
  {
    if (allSuspects[x] != "")
    {
      return allSuspects[x];
    }
  }
}

string Computer::roomFinalHelper()
{
  string allRooms[] = {"UMC", "Farrand Field", "CSEL", "Kittredge", "Folsom Field", "C4C"};

  for (int i = 0; i < aTable -> tableSize; i++)
  {
    for (int j = 0; j < 6; j++)
    {
      if (aTable[i].name == allRooms[j])
      {
        allRooms[j] == "";
      }
    }
  }

  for (int k = 0; k < pTable -> tableSize; k++)
  {
    for (int n = 0; n < 6; n++)
    {
      if (pTable[k].name == allRooms[n])
      {
        allRooms[n] == "";
      }
    }
  }

  for (int x = 0; x < 6; x++)
  {
    if (allRooms[x] != "")
    {
      return allRooms[x];
    }
  }
}

string Computer::FinalAccusation()
{
  string weapon;
  string suspect;
  string room;

  cout << "The computer has made it into the " << room << "." << endl;
  cout << "The computer will now make a final accusation as to who it thinks committed the murder." << endl;

  weapon = weaponFinalHelper();

  suspect = suspectFinalHelper();

  room = roomFinalHelper();

  cout << "Computer's Final Accusation:" << endl;
  cout << "Weapon: " << weapon << endl;
  cout << "Suspect: " << suspect << endl;
  cout << "Room: " << room << endl;

  string compFinal = "Final Accusation: " + weapon + ", " + suspect + ", " + room;

  return compFinal;
}

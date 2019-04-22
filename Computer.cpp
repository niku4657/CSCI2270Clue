#include <iostream>
#include <vector>
#include "Computer.hpp"
#include "HashTable.hpp"
#include "Player.hpp"
using namespace std;

Computer::Computer()
{
  //Leave empty.
}

bool Computer::canMakeFinal()
{
  int count = 0;

  for(int i = 0; i < 3; i++)
  {
    Card* temp = aTable -> table[i];

    while(temp != NULL)
    {
      count++;
      temp = temp -> next;
    }
  }

  for(int k = 0; k < 3; k++)
  {
    Card* temp = pTable -> table[k];

    while(temp != NULL)
    {
      count++;
      temp = temp -> next;
    }
  }

  if(count == 15)
  {
    return true;
  }

  return false;
}

string Computer::ChooseTurn()
{
  int computerTurn;
  string compResult;
  int roll = Dice();

  //random function between 1 - 2
  computerTurn = rand() % 3 + 1;

  if (computerTurn == 1)
  {
    compResult = Suggest(roll);
    return compResult;
  }
  else if (computerTurn == 2 && canMakeFinal())
  {
    compResult = FinalAccusation();
    return compResult;
  }
  else
  {
    return "Quit Turn";
  }
}

int Computer::Dice()
{
	return rand() % 6 + 1; //Random from 1 to 6 is returned.
}

void Computer::printCards()
{
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
    cout << "The computer will now choose one of the following rooms to go into:" << endl << endl;
    cout << "UMC" << endl;
    cout << "Farrand Field" << endl;
    cout << "CSEL" << endl;
    cout << "Kittredge" << endl;
    cout << "Folsom Field" << endl;
    cout << "C4C" << endl << endl;

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

    cout << "The computer has made it into the " << room << "!" << endl << endl;
    cout << "The computer will now make a suggestion as to who it thinks committed the murder." << endl << endl;

    cout << "Computer's Suggestion:" << endl << endl;
    cout << "Room: " << room << endl;
    suspect = suspectHelper();
    cout << "Suspect: " << suspect << endl;
    weapon = weaponHelper();
    cout << "Weapon: " << weapon << endl << endl;

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

  Card* temp = aTable -> table[0];

  while(temp != NULL)
  {
    for (int j = 0; j < 6; j++)
    {
      if (temp -> name == allWeapons[j])
      {
        allWeapons[j] == "";
      }
    }

    temp = temp -> next;
  }

  Card* temp2 = pTable -> table[0];

  while(temp2 != NULL)
  {
    for (int j = 0; j < 6; j++)
    {
      if (temp2 -> name == allWeapons[j])
      {
        allWeapons[j] == "";
      }
    }

    temp2 = temp2 -> next;
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

  Card* temp = aTable -> table[1];

  while(temp != NULL)
  {
    for (int j = 0; j < 6; j++)
    {
      if (temp -> name == allSuspects[j])
      {
        allSuspects[j] == "";
      }
    }

    temp = temp -> next;
  }

  Card* temp2 = pTable -> table[1];

  while(temp2 != NULL)
  {
    for (int j = 0; j < 6; j++)
    {
      if (temp2 -> name == allSuspects[j])
      {
        allSuspects[j] == "";
      }
    }

    temp2 = temp2 -> next;
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

  Card* temp = aTable -> table[2];

  while(temp != NULL)
  {
    for (int j = 0; j < 6; j++)
    {
      if (temp -> name == allRooms[j])
      {
        allRooms[j] == "";
      }
    }

    temp = temp -> next;
  }

  Card* temp2 = pTable -> table[2];

  while(temp2 != NULL)
  {
    for (int j = 0; j < 6; j++)
    {
      if (temp2 -> name == allRooms[j])
      {
        allRooms[j] == "";
      }
    }

    temp2 = temp2 -> next;
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

  cout << "The computer has made it into the " << room << "." << endl << endl;
  cout << "The computer will now make a final accusation as to who it thinks committed the murder." << endl << endl;

  weapon = weaponFinalHelper();

  suspect = suspectFinalHelper();

  room = roomFinalHelper();

  cout << "Computer's Final Accusation:" << endl << endl;
  cout << "Weapon: " << weapon << endl;
  cout << "Suspect: " << suspect << endl;
  cout << "Room: " << room << endl << endl;

  string compFinal = "Final Accusation: " + weapon + ", " + suspect + ", " + room;

  return compFinal;
}

Card* Computer::RevealCard(string weapon, string suspect, string room)
{
  Card* cards[3];
  cards[0] = aTable -> searchItem(0, weapon);
  cards[1] = aTable -> searchItem(6, suspect);
  cards[2] = aTable -> searchItem(12, room);

  vector<Card*> notNull;
  for(int i = 0; i < 3; i++)
  {
    if(cards[i] != NULL)
    {
      notNull.push_back(cards[i]);
    }
  }

  if(notNull.size() == 0)
  {
    return NULL;
  }
  else
  {
    int random = rand() % notNull.size();
    return notNull[random];
  }
}

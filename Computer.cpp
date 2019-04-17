#include <iostream>
#include "Computer.hpp"
#include "HashTable.hpp"

using namespace std;

Computer::Computer(){

}

void Computer::RandomTurn(){
  int computerTurn;
  cout << "Main Menu" << endl;
  cout << "1. Suggest" << endl;
  cout << "2. Final Accusation" << endl;
  cout << "3. Quit Turn" << endl;

  //random function between 1 - 3
  computerTurn = rand() % 3 + 1;

  if (computerTurn == 1)
  {
    RandomSuggest();
  }
  else if (computerTurn == 2)
  {
    FinalAccusation();
  }
  else if (computerTurn == 3)
  {
    cout << "You have quit your turn" << endl;
  }

}

void suspectHelper(){
  int randSuspect;
  string computerSuggestSuspect;
  //rand function between 6 and 11
  randSuspect = rand() % 6 + 6;

  //call search function with that random integer
  Card *temp = cTable.searchItem(randSuspect);

  if (temp == NULL)
  {
    suspectHelper();
  }
  else if (temp != NULL)
  {
    computerSuggestSuspect = temp->name;
  }
}

void weaponHelper(){
  int randWeapon;
  string computerSuggestWeapon;
  //rand function between 12 and 17
  randWeapon = rand() % 6 + 12;

  //call search function with that random integer
  Card *tempW = cTable.searchItem(randWeapon);

  if (tempW == NULL)
  {
    weaponHelper();
  }
  else if (tempW != NULL)
  {
    computerSuggestWeapon = tempW->name;
  }
}

void Computer::RandomSuggest(bool final){
  //After the dice roll
  string computerRoomChoice;
  string computerSuggestRoom;
  string computerSuggestSuspect;
  string computerSuggestWeapon;
  int computerDice;

  if (roll == 1 || roll == 3 || roll == 5)
  {
    cout << "UMC" << endl;
    cout << "Farrand Field" << endl;
    cout << "CSEL" << endl;
    cout << "Kittredge Central" << endl;
    cout << "Folsom Field" << endl;
    cout << "C4C" << endl;

    computerDice = rand() % 6 + 1;

    switch(stoi(computerRoomChoice))
    {
      case 1:
        computerSuggestRoom = "UMC";
      break;

      case 2:
        computerSuggestRoom = "Farrand Field";
      break;

      case 3:
        computerSuggestRoom = "CSEL";
      break;

      case 4:
        computerSuggestRoom = "Kittredge Central";
      break;

      case 5:
        computerSuggestRoom = "Folsom Field";
      break;

      case 6:
        computerSuggestRoom = "C4C";
      break;
    }

    cout << "The computer has made it into the " << computerSuggestRoom << endl;
    cout << "The computer will now make a suggestion as to who committed the murder" << endl;

    cout << "Computer's Suggestion:" << endl;
    cout << "Room: " << computerSuggestRoom << endl;
    suspectHelper();
    cout << "Suspect: " << computerSuggestSuspect << endl;
    weaponHelper();
    cout << "Weapon: " << computerSuggestWeapon << endl;
  }
  else
  {
    //switch turn function - main?
  }
}

void Computer::FinalAccusation(){
  //After dice roll
  //one choice to get the envelope cards correct
  RandomSuggest(); //Basically make a Suggestion

  //search envelope hash table

  //if all cards are found
  cout << "Congratulations! You successfully uncovered the details of the murder!" << endl;

  //if none are found or at least one doesn't match
  cout << "Sorry! You didn't accurately solve the murder mystery." << endl;

}

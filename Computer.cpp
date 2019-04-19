#include <iostream>
#include "Computer.hpp"
#include "HashTable.hpp"
using namespace std;

string Computer::ChooseTurn(){
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
    compResult = FinalAccusation(h);
    return compResult;
  }
  else if (computerTurn == 3)
  {
    cout << "The computer has quit its turn. It is now the human's turn." << endl; //Switch turn in int main
    return "Quit Turn";
  }
}

void Computer::printCards(){
  cTable.printTable();
}
string suspectHelper(){
  int randSuspect;
  string computerSuggestSuspect;
  //rand function between 6 and 11
  randSuspect = rand() % 6 + 6;

  //call search function with that random integer
  Card *temp = cTable.searchItem(randSuspect);

  if(temp != NULL)
  {
    computerSuggestSuspect = temp->name;
  }

  return computerSuggestSuspect;
}

string weaponHelper(){
  int randWeapon;
  string computerSuggestWeapon;
  //rand function between 12 and 17
  randWeapon = rand() % 6 + 12;

  //call search function with that random integer
  Card *tempW = cTable.searchItem(randWeapon);

  if (tempW != NULL)
  {
    computerSuggestWeapon = tempW->name;
  }

  return computerSuggestWeapon;
}

string Computer::Suggest(int roll){
  //After the dice roll
  string computerRoomChoice;
  string computerSuggestRoom;
  string computerSuggestSuspect;
  string computerSuggestWeapon;
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

    switch(stoi(computerDice))
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
        computerSuggestRoom = "Kittredge";
      break;

      case 5:
        computerSuggestRoom = "Folsom Field";
      break;

      case 6:
        computerSuggestRoom = "C4C";
      break;
    }

    cout << "The computer has made it into the " << computerSuggestRoom << endl;
    cout << "The computer will now make a suggestion as to who it thinks committed the murder" << endl;

    cout << "Computer's Suggestion:" << endl;
    cout << "Room: " << computerSuggestRoom << endl;
    computerSuggestSuspect = suspectHelper();
    cout << "Suspect: " << computerSuggestSuspect << endl;
    computerSuggestWeapon = weaponHelper();
    cout << "Weapon: " << computerSuggestWeapon << endl;

    string compSuggest = computerSuggestWeapon + ", " + computerSuggestSuspect + ", " + computerSuggestRoom;

    return compSuggest;
  }
  else
  {
    return "";
  }
}

string Computer::FinalAccusation(){
  bool inEnvelope;
  //After dice roll, one choice to get the envelope cards correct
  RandomSuggest(); //Basically make a Suggestion

  //search envelope hash table -->helper function called checkEnvelopeComputer
  inEnvelope = checkEnvelope(computerSuggestWeapon, computerSuggestSuspect, computerSuggestRoom);
  //if all cards are found
  if (inEnvelope == true)
  {
    cout << "You lost! The computer successfully uncovered the details of the murder." << endl;
  }
  else
  {
    //if none are found or at least one doesn't match
    cout << "The computer didn't accurately solve the murder mystery. " << endl;
  }

  cout << "The correct details to this mystery were: " << endl;
  h.printTable();
  return "";
}

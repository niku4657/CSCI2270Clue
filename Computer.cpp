#include <iostream>
#include "Computer.hpp"
#include "HashTable.hpp"

using namespace std;

int Computer::ChooseTurn(HashTable h){
  int computerTurn;
  cout << "Main Menu" << endl;
  cout << "1. Suggest" << endl;
  cout << "2. Final Accusation" << endl;
  cout << "3. Quit Turn" << endl;
  cout << "4. Quit Game" << endl;

  //random function between 1 - 3
  computerTurn = rand() % 4 + 1;

  if (computerTurn == 1)
  {
    Suggest();
    return 1;
  }
  else if (computerTurn == 2)
  {
    FinalAccusation(h);
    return 2;
  }
  else if (computerTurn == 3)
  {
    cout << "The computer has quit its turn" << endl; //Switch turn in int main
    return 3;
  }
  else if (computerTurn == 4)
  {
    cout << "The computer has quit the game" << endl;
    return 4;
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

void Computer::Suggest(int roll){
  //After the dice roll
  string computerRoomChoice;
  string computerSuggestRoom;
  string computerSuggestSuspect;
  string computerSuggestWeapon;
  int computerDice;

  if (roll == 1 || roll == 3 || roll == 5)
  {
    cout << "The computer will now choose a room to go into" << endl;
    cout << "UMC" << endl;
    cout << "Farrand Field" << endl;
    cout << "CSEL" << endl;
    cout << "Kittredge Central" << endl;
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
    cout << "The computer will now make a suggestion as to who committed the murder" << endl;

    cout << "Computer's Suggestion:" << endl;
    cout << "Room: " << computerSuggestRoom << endl;
    computerSuggestSuspect = suspectHelper();
    cout << "Suspect: " << computerSuggestSuspect << endl;
    computerSuggestWeapon = weaponHelper();
    cout << "Weapon: " << computerSuggestWeapon << endl;
  }
  else
  {
    return;
  }
}

void Computer::FinalAccusation(HashTable h){
  bool inEnvelope;
  //After dice roll, one choice to get the envelope cards correct
  RandomSuggest(); //Basically make a Suggestion

  //search envelope hash table -->helper function called checkEnvelopeComputer
  inEnvelope = checkEnvelope(computerSuggestWeapon, computerSuggestSuspect, computerSuggestRoom, h);
  //if all cards are found
  if (inEnvelope == true)
  {
    cout << "Congratulations! You successfully uncovered the details of the murder!" << endl;
  }
  else
  {
    //if none are found or at least one doesn't match
    cout << "Sorry! You didn't accurately solve the murder mystery." << endl;
  }

  cout << "The correct answer is:" << endl;
  h.printTable();
  return;
}

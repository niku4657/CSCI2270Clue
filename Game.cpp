#include <iostream>
#include "ClueCard.hpp"
#include "HashTable.hpp"
#include "Player.hpp"
#include "Human.hpp"
#include "Computer.hpp"

void Suggest(bool final, int roll)
{
  string enterRoom;
  string suggestSuspect;
  string suggestWeapon;
  if (final == true)
  {
    //final accusation
  }
  else
  {
    if (roll == 1 || roll == 3 || roll == 5)
    {
      cout << "UMC" << endl;
      cout << "Farrand Field" << endl;
      cout << "CSEL" << endl;
      cout << "Kittredge Central" << endl;
      cout << "Folsom Field" << endl;
      cout << "C4C" << endl;

      cin >> enterRoom;
      //you are in a room
      cout << "You have made it into the " << enterRoom << endl;
      cout << "You can now make a suggestion of who you think committed the murder" << endl;

      cout << "Your Suggestion:" << endl;
      cout << "Room: " << enterRoom << endl;

      cout << "Suspect";
      cin >> suggestSuspect;
      cout << endl;

      cout << "Weapon";
      cin >> suggestSuspect;

      //go search other player's "printTable" ... in the main function
    }
    else
    {
      //you are not in a room, continue to the next person's turn - switchTurn funciton
    }
  }
}

int main()
{
  string option;
  cin >> option;

  while(option != "4")
  {
    switch(stoi(option))
    {
      case 1:
      int roll = aPlayer.Dice();
      cout << "You rolled a " << roll << endl;
      cout << "Choose from the menu again:" << endl;
      aPlayer.Turn();
      cin >> option;
    }
  }
}

#include <iostream>
#include "Human.hpp"

using namespace std;

Human::Human()
{

}

void Human::AcceptTurn(){


}

void Human::Suggest(bool final, int roll){
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

void Human::ChooseMove(){


}

void Human::FinalAccusation(){


}

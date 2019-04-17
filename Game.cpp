#include <iostream>
#include "ClueCard.hpp"
#include "HashTable.hpp"
#include "Player.hpp"
#include "Human.hpp"
#include "Computer.hpp"

void MainMenu()
{
  cout << "Main Menu" << endl;
  cout << "1. Suggest" << endl;
  cout << "2. Final Accusation" << endl;
  cout << "3. Quit Turn" << endl;
  cout << "4. Quit Game" << endl;
}

int rollDice()
{
	return random() % 6 + 1; //Random from 1 to 6 is returned.
}

int main()
{
  ClueCard cc;
  string option;
  string enterRoom;
  string suggestSuspect;
  string suggestWeapon;

  int roll = rollDice();
  cout << "You rolled a " << roll << endl;

  while(option != "3") //As long as the option is not 3...
  {
    MainMenu(); //Display the options.
    getline(cin, option); //Set option equal to input.

    switch(stoi(option)) //Depending on the option...
    {
      case 1:
        if (roll == 1 || roll == 3 || roll == 5)
        {
          cout << "UMC" << endl;
          cout << "Farrand Field" << endl;
          cout << "CSEL" << endl;
          cout << "Kittredge Central" << endl;
          cout << "Folsom Field" << endl;
          cout << "C4C" << endl;

          getline(cin, enterRoom);
          //you are in a room
          cout << "You have made it into the " << enterRoom << endl;
          cout << "You can now make a suggestion of who you think committed the murder" << endl;

          cout << "Your Suggestion:" << endl;
          cout << "Room: " << enterRoom << endl;

          cout << "Suspect";
          getline(cin, suggestSuspect);
          cout << endl;

          cout << "Weapon";
          getline(cin, suggestWeapon);
          cout << endl;

          //SEARCH COMP'S TABLE!!
        }
        else
        {
          cout << "You can't enter a room, it is now the computer's turn.";
          cout << endl;

          //SWITCH TO COMPUTER PLAYER!!
        }

        break;

      case 2:
          cout << "Your Final Accusation:" << endl;

          cout << "Room:"
          getline(cin, enterRoom);

          cout << "Suspect";
          getline(cin, suggestSuspect);
          cout << endl;

          cout << "Weapon";
          getline(cin, suggestWeapon);
          cout << endl;

          //Add bool function to the clue card class that checks if correct!!!!
          if(cc.checkEnvelope(enterRoom, suggestSuspect, suggestWeapon))
          {
            cout << "Congratulations you won the game!!!!" << endl;
          }
          else
          {
            cout << "You lost the game..." << endl;
          }

          //QUIT THE GAME!!

        break;

      case 3:

        //THIS IS WHERE ALL OF THE COMPUTER'S TURN IS TAKEN CARE OF

        break;

      case 4:

        //Print the following:
        cout << "Goodbye!" << endl;

        break;
    }
  }
}

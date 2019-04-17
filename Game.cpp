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

int main()
{
  ClueCard cc;
  string option;

  while(option != "3") //As long as the option is not 3...
  {
    MainMenu(); //Display the options.
    getline(cin, option); //Set option equal to input.

    switch(stoi(option)) //Depending on the option...
    {
      case 1:


        break;

      case 2:


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

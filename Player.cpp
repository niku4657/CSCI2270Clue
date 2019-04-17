#include <iostream>
#include "Player.hpp"
#include "Human.hpp"
#include "Computer.hpp"

using namespace std;


void Player::Turn(){

}

int Player::Dice(){
   int roll;
   roll = rand() % 7;

   cout << "You rolled a " << roll << endl;
}

void Human::Move(){

}

#ifndef GAME_HPP
#define GAME_HPP
#include <iostream>
#include <string>
#include "ClueCard.hpp"
#include "Player.hpp"
#include "Computer.hpp"
#include "Human.hpp"
#include "HashTable.hpp"

using namespace std;

class Game
{
    public:
        ClueCard cc;
        Player players[3];
        Game();
        ~Game();
        void initializePlayersArray();
        void distributeCards();
        Card* humanRevealCard(string weapon, string suspect, string room, int num);
        Card* computerRevealCard(string weapon, string suspect, string room, int num);
        void startGame();
};

#endif

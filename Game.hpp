#ifndef GAME_HPP
#define GAME_HPP
#include <iostream>
#include <string>
#include "ClueCard.hpp"
#include "Player.hpp"
using namespace std;

class Game
{
    public:
        ClueCard cc;
        Player* players[3];
        Game();
        ~Game();
        void initializePlayersArray();
        void distributeCards();
        void duplicateCard(Card* card, Player p);
        Card* humanRevealCard(string weapon, string suspect, string room);
        Card* computerRevealCard(string weapon, string suspect, string room);
        void startGame();
};

#endif

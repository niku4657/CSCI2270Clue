#ifndef GAME_HPP
#define GAME_HPP
#include <iostream>
#include <string>
#include "ClueCard.hpp"
#include "Player.hpp"
using namespace std;

class ClueCard{
    private:
        ClueCard cc;
        Player players[2];

    public:
        void initializePlayersArray();
        void distributeCards();
        void duplicateCard(Card* card, Player p);
        Card* humanRevealCard(string weapon, string suspect, string room)
        Card* computerRevealCard(string weapon, string suspect, string room)
        void startGame();
};

#endif

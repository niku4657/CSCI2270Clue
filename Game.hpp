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
        void duplicateCard(int key, string name);
        Card* revealCard(string weapon, string suspect, string room);
        void startGame();
};

#endif

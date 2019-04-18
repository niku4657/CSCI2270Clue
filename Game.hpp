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
        Player players[3];

    public:
        void distributeCards();
        void duplicateCard(int key, string name);
        void initializePlayersArray();
        void startGame();
};

#endif

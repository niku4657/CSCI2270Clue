#ifndef CLUECARD_HPP
#define CLUECARD_HPP
#include <iostream>
#include <string>
#include "HashTable.hpp"

using namespace std;

class ClueCard{
    private:
        Card weapon[6];
        Card suspect[6];
        Card room[6];
        HashTable envelope(3);
        //HashTable allCards;
        Player players[3];

    public:
        void addCardArray(Card cards[], int key, string name);
        void fillInWeapons();
        void fillInSuspects();
        void fillInRooms();
        void shuffleCards();
        //void combineCards();
        void distrubuteCards(); // pass in player
        // string getCardKey();
        //void setCardType(string);
        //string getCardName();
        //void setCardName(string);
        string revealCard();
        void printArray();
};

#endif

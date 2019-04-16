#ifndef CLUECARD_HPP
#define CLUECARD_HPP
#include <iostream>
#include <string>
#include "HashTable.hpp"
using namespace std;

class ClueCard{
    private:
        HashTable player1;
        HashTable player2;
        HashTable player3;
        HashTable envelope;
        HashTable allCards;

    public:
        void shuffleCards();
        void combineCards();
        void distrubuteCards();
        string getCardType();
        string getCardName();
        string revealCard();
}

#endif

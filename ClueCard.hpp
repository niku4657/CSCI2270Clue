#ifndef CLUECARD_HPP
#define CLUECARD_HPP
#include <iostream>
#include <string>
#include "HashTable.hpp"

using namespace std;

class ClueCard{
    private:
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

#ifndef CLUECARD_HPP
#define CLUECARD_HPP
#include <iostream>
#include <string>
#include "HashTable.hpp"

using namespace std;

class ClueCard{
    private:
        HashTable weapon;
        HashTable suspect;
        HashTable building;
        HashTable envelope;
        HashTable allCards;

    public:
        void shuffleCards();
        void combineCards();
        void distrubuteCards();
        string getCardType();
        //void setCardType(string);
        string getCardName();
        //void setCardName(string);
        string revealCard();
}

#endif

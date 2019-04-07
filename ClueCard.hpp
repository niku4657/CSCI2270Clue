#ifndef CLUECARD_HPP
#define CLUECARD_HPP
#include <iostream>
#include <string>
#include "LinkedList.hpp"

using namespace std;

class ClueCard{
    private:
        LinkedList weapon;
        LinkedList suspect;
        LinkedList building;
        LinkedList envelope;
        LinkedList allCards;

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
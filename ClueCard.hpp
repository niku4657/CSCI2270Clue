#ifndef CLUECARD_HPP
#define CLUECARD_HPP
#include <iostream>
#include <string>
#include "HashTable.hpp"
using namespace std;

class ClueCard
{
    private:
        Card weapon[6];
        Card suspect[6];
        Card room[6];
        HashTable envelope();
        Card allCards[];

    public:
        void addCardArray(Card cards[], int key, string name);
        void fillInWeapons();
        void fillInSuspects();
        void printArray();
        void shuffleCards();
        void fillInRooms();
        void mergeArrays();
};

#endif

#ifndef CLUECARD_HPP
#define CLUECARD_HPP
#include <iostream>
#include <string>
#include <vector>
#include "HashTable.hpp"
using namespace std;

class ClueCard
{
    public:
        Card weapon[6];
        Card suspect[6];
        Card room[6];
        HashTable* envelope= new HashTable();
        Card allCards[18];
        ClueCard();
        ~ClueCard();
        void addCardArray(Card cards[], int index, int key, string name);
        void fillInWeapons();
        void fillInSuspects();
        void printArray();
        void shuffleCards();
        void fillInRooms();
        void mergeArrays();
        bool checkEnvelope(string weapon, string suspect, string room);
};

#endif

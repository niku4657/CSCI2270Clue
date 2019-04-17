#ifndef HUMAN_HPP
#define HUMAN_HPP
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

class Human : public Player
{
  private:
    HashTable *hTable;

  public:
    //Choose from menu to roll, suggest, and make final accusation.
    void ChooseTurn();
    //Roll Function
    int Dice();
    //Print out Cards
    void printCards();
    //Suggest Function
    void Suggest(int roll);
    //Helper for Final Accuation
    bool checkEnvelope(string weapon, string suspect, string room);
    //Final Accusation
    void FinalAccusation(HashTable h);
};

#endif

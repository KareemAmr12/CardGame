#pragma once
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

class cardType
{
public:
    char suit;
    char rank;
};

class Deck : public cardType
{
public:
    Deck();  //defult constructor
    ~Deck();  //defult destructor
    void Create_Fresh_Deck();  //function to create a fresh deck
    bool EmptyDeck() const;  //function to check if deck is empty
    cardType RemoveCard();  //function to remove card from the deck
    void AddCard(const cardType&);  //function to add a card to the deck
    void Shuffle_Deck(); //function to shuffle the deck
    void Cut_Deck();  //function to swap half the deck with the other half
    void Display_Deck() const;  //function to display the deck

private:
    cardType D[52];
    int top;
    void swap(int i, int k);
};
#include "Deck.h"

Deck::Deck()
{
    top = -1;
}

Deck::~Deck()
{}

bool Deck::EmptyDeck() const
{
    if (top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Deck::AddCard(const cardType& c)
{
    top++; //we increment the top and add the card to the deck
    D[top] = c;
}

cardType Deck::RemoveCard()
{
    cardType temp = cardType();
    if (top > -1)
    {
        temp = D[top];
        top--; //we decrement the top and remove the top card
    }
    return temp;
}

void Deck::Create_Fresh_Deck()
{
    cardType c;
    string v = "23456789TJQKA";
    top = -1;
    for (int i = 0; i < 4; i++)  //we do a loop to create the deck's cards suit (4 suits) and rank (13 ranks)
    {
        for (int j = 0; j < 13; j++)
        {
            c.suit = char(i + 3); 
            c.rank = v[j];
            AddCard(c);
        }
    }
}

void Deck::swap(int i, int k) 
{
    cardType temp;
    temp = D[i]; //we put card i into temp and then swap the cards
    D[i] = D[k];
    D[k] = temp;
}

void Deck::Shuffle_Deck() 
{
    srand((unsigned)time(NULL));  //we generate random k to make the shuffle random
    for (int i = 51; i >= 1; i--)
    {
        int k = rand() % (i + 1);
        swap(i, k);
    }
}

void Deck::Cut_Deck()
{
    for (int i = 0; i < 26; i++)
    {
        swap(i, (i + 26));  //here we make a loop to swap each card with the card after 26 cards (so that we swap the first half of the deck with the second half
    }
}

void Deck::Display_Deck() const
{
    if (!EmptyDeck()) //here we check that the deck is not empty before procceding
    {
        for (int i = 0; i <= top; i++) //here we do a loop to display each card in the deck, displaying its suit and rank
        {
            cout << "Card number #" << i + 1 << " suit: " << D[i].suit << " rank: " << D[i].rank << endl;
        }
    }
}
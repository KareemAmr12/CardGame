#include "Deck.h"

int main()
{
    const int players = 4; //here is our number of players in the game
    string v = "23456789TJQKA";

    Deck cdeck; //here is the deck which will be shuffled and given to the players
    Deck Hand[players]; //this is each player's hand or each player deck 
    cardType c; //this is just a card to be used as a temp card
    cardType wCard; //this is the winning card in each round
    cardType cards[players]; //this is the cards which are put by the players each round
    int score[players]; //this is the score of the players

    int N = 0;
    int p; //this is a player to be used as temp later
    int wp;  //this is the winner player in each round
    

    cdeck.Create_Fresh_Deck(); //here we create the deck 
    cdeck.Shuffle_Deck();  //here we shuffle the deck
    cdeck.Cut_Deck();  //here we just swap the first half with the second half of the deck
    cout << "Main deck consists of the following cards: " << endl;
    cdeck.Display_Deck();  //here we display the deck after being shuffled and created
    cout << endl;

    while (!cdeck.EmptyDeck())  //here we use this loop to split the main deck between the players (each player recieves 13 cards)
    {
        p = N % players; //here we use N to change the player that recieves a card each time the loop restarts so that each player gets one card from the top of the main deck each time
        c = cdeck.RemoveCard();
        Hand[p].AddCard(c);
        N++;
    }

    for (int i = 0; i < players; i++) //here we display the hands of the players
    {
        score[i] = 0;
        cout << "Hand of player #" << (i + 1) << " : " << endl;
        Hand[i].Display_Deck();
        cout << endl;
    }

    while (!Hand[0].EmptyDeck()) //here we actually play the game after setuping up everything
    {
        for (p = 0; p < players; p++) //here we put the cards on the table
        {
            cards[p] = Hand[p].RemoveCard();
        }
        int max = -1; //we declare max to be the maximum card value in a round to determine the winner
        for (p = 0; p < players; p++)  //here we make a loop to decide the winner card of the cards on the table in a round
        {
            int currentCardValue; //the current card in this loop which changes every loop
            int rank; 
            if (cards[p].rank > '9')  //here we do an if statement to check if the rank is more than 9
            {
                switch (cards[p].rank)  //here we assign values for cards with ranks more than 9 like A and K 
                {
                case 'A':
                    rank = 14;
                    break;
                case 'K':
                    rank = 13;
                    break;
                case 'Q':
                    rank = 12;
                    break;
                case 'J':
                    rank = 11;
                    break;
                case 'T':
                    rank = 10;
                    break;
                default:
                    rank = 0;
                }
            }
            else
            {
                rank = static_cast<int>(cards[p].rank) - 48;  //if the rank is less than 9 we use askii code to get the value of each rank
            }
            currentCardValue = rank + static_cast<int>(cards[p].suit); //here we add the values of each card

            if (currentCardValue > max) //here we check the card on the table with the maximum value and the winner player in that round
            {
                max = currentCardValue;
                wp = p;
            }

        }
        score[wp] += max; //here we add the score to the winner player

        cout << "cards on table: \n"; //here we display the cards which are on the table 
        for (p = 0; p < players; p++)
        {
            cout << cards[p].rank << cards[p].suit;
            cout << endl;
        }
        cout << endl;
        cout << "Winning card is: " << cards[wp].rank << cards[wp].suit << endl; //here we display the winning card each round
        cout << "Round winner is player #" << wp + 1 << endl;  //here we display the winner in each round

        cout << "Press Enter to advance\n";  //here we pause the game (wait for the user to press enter) to continue to the next round 
        cin.get();
    }

    for (int i = 0; i < players; i++) //here we display the scores of each player at the end of the game and this marks the end of the game
    {
        cout << "Player number " << i + 1 << " scored: " << score[i] << endl;
    }

    system("pause");
    return 0;
}
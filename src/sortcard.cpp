// SortCard.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "cardlib.h"

#include <string>
#include <iostream>
using namespace std;

const int maxCard = 20;

aCard thePack[maxCard];

aCard* bubbleSort(aCard c[])
{
    aCard x;

    for (int j = 0; j < maxCard; j++)
    {
        for (int i = 0; i < maxCard; i++)
        {
            if (c[i].cardVal < c[i + 1].cardVal)
            {
                x = c[i + 1];
                c[i + 1] = c[i];
                c[i] = x;
            }
        }
    }    
    return c;
}

aCard* quickSort(aCard c[], start = , end = )
{
    aCard x;
    if()

}

void printPack(aCard c[])
{
    string suteNames[] = {"♥️ Hearts", "♣️ Clubs", "♦️ Diamonds", "♠️ Spades"};
    string cardValue[] = {"NULL", "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    for (int i=0; i < maxCard; i++)
    {
        cout << cardValue[c[i].cardVal] << " of " << suteNames[c[i].cardSuit] << endl;
    }
}

int main()
{
    cout << "Card Sorting!\n";

    for (int ct = 0; ct < maxCard; ct++)
    {
        thePack[ct] = getCard("30021591");   // change to your student number
    }
    cout << "\nYour card are: " << endl;
    printPack(thePack);
    aCard* sortedCards;
    sortedCards = bubbleSort(thePack);
    cout << "\nSorted card are: " << endl;
    printPack(sortedCards);
}

// # Questions

// How do I covert "thePack[ct].cardSuit" to Sute names?

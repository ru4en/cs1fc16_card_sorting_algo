// SortCard.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "cardlib.h"

#include <string>
#include <iostream>
using namespace std;

const int maxCard = 7;

aCard thePack[maxCard];

aCard* bubbleSort(aCard c[])
{
    aCard x;
    bool sorted=false;
    while (sorted!=true) {
        for (int i = 0; i < maxCard; i++)
        {
            if (c[i].cardSuit > c[i + 1].cardSuit)
            {
                x = c[i + 1];
                c[i + 1] = c[i];
                c[i] = x;
                
            }else
            {
                sorted=true;
            }
        } 
    }
    return c;
}

void printPack(aCard c[])
{
    string suteNames[] = {"Hearts", "Clubs", "Diamonds", "Spades"};
    for (int i=0; i < maxCard; i++)
    {
        cout << c[i].cardVal << " of ";
        cout << suteNames[c[i].cardSuit] << endl;
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

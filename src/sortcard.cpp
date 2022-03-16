// SortCard.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "cardlib.h"

#include <string>
#include <iostream>
using namespace std;

const int maxCard = 20;

aCard thePack[maxCard];

int bubbleSortCounter = 0;
int quickSortCounter = 0;

bool corOrder(aCard a, aCard b, bool val) {
    if (val)
    {
        if (a.cardVal < b.cardVal)
        {
            return 1;
        }else
        {
            return 0;
        }
    }else
    {
        if (a.cardSuit < b.cardSuit)
        {
            return 1;
        }else
        {
            return 0;
        }
    }
    return -1;
}

aCard* bubbleSort(aCard c[], bool val)
{       
    aCard x;

    for (int j = 0; j < (maxCard-1); j++)
    {
        for (int i = 0; i < (maxCard-1); i++)
        {
            if (corOrder(c[i], c[i+1], val) == 1)
            {
                x = c[i + 1];
                c[i + 1] = c[i];
                c[i] = x;
            }
            bubbleSortCounter++;
        }
    }    
    return c;
}

int partition(aCard c[], int left, int right)
{
    int p = left - right;
    int store;
    aCard x;
    quickSortCounter++;

    for (int i = 0; i < (p); i++)
    {
        if (c[i].cardVal <= c[right].cardVal)
        {
            x = c[left];
            c[left] = c[i];
            c[i] = x;
        }
    }

    x = c[left];
    c[left] = c[right];
    c[right] = x;

    return left;
}

aCard* quickSort(aCard c[], int left, int right)
{
    int piv;

    if (left > right)
    {
        piv = partition(c, left, right);
        quickSort(c, left, (piv-1));
        quickSort(c, left, (piv-1));
    }
    return c;
}

void printPack(aCard c[])
{
    string suteNames[] = {"♥️ Hearts", "♣️ Clubs", "♦️ Diamonds", "♠️ Spades"};
    string cardValue[] = {"-", "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
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

    aCard* bubbleSortedCards;
    bubbleSortedCards = bubbleSort(thePack, 1);
    bubbleSortedCards = bubbleSort(bubbleSortedCards, 0);
    cout << "\nBubble Sorted card are: " << endl;
    printPack(bubbleSortedCards);
    cout << bubbleSortCounter << " moves for " << maxCard << " cards." << endl;

    aCard* quickSortedCards;
    quickSortedCards = quickSort(thePack, 0, maxCard-1);
    cout << "\nQuick Sorted card are: " << endl;
    printPack(quickSortedCards);
    cout << quickSortCounter << " moves for " << maxCard << " cards." << endl;
}
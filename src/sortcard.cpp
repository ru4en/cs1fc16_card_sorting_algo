// SortCard.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "cardlib.h"                                // importing the library to get cards. Algorithm provided by Richard Mitchell.

#include <string>                                   // importing Strings and stand I/O library
#include <iostream>
using namespace std;                                // namespace so std:: doesn't have to be repeated (not good practice)

const int maxCard = 20;                             // setting the maximum number of cards as a constant global variable

aCard thePack[maxCard];                             // the set of cards or deck of cards
aCard thePack2[maxCard];
int sortCounter = 0;                                //  counter variables to measure number of checks and moves
int corOrderCounter = 0;

int corOrder(aCard a, aCard b, int val)             // checker function that returns true if a is smaller than b. val is used to determine if cardVal or cardSuit is being checked
{
    corOrderCounter++;                              // checker function counter increments by one

    if (val != 0)                                   //if value of card is what requested to be checked then ...
    {
        if (a.cardVal < b.cardVal){return true;}    // returns true if cardVal of a is smaller than b
        else return false;
    }
    else if(val != 1)                               // does the same but with cardSuit
    {
        if (a.cardSuit < b.cardSuit){return true;}
        else return false;
    }
    return -1;
}

aCard* bubbleSort(aCard c[], bool val)               // bubbleSort algorithm which returns a pointer to a card, and takes in a list of cards and boolean values if to sort by  card value or card sute
{       
    aCard x;                                         // Temporary variable x to hold cards during sorting

    for (int j = 0; j < (maxCard-1); j++)            // for i in maxCard-1 and for j in maxCard-1 loops trough the pack, hence the big O sorting in exponential time.
    {
        for (int i = 0; i < (maxCard-1); i++)
        {
            if (corOrder(c[i], c[i+1], val) == 1)    // used the checker function to check if card i has a greater value than card i+1 if so do the following
            {
                swap( c[i], c[i + 1]);
                sortCounter++;                       // sort counter increments yet again
            }
        }
    }    
    return c;                                        // return a pointer of the array of sorted cards
}

aCard* swap(aCard c[], int pos1, int pos2){
	aCard x;
	x = c[pos1];
	c[pos1] = c[pos2];
	c[pos2] = x;
    return c;
}

int partition(aCard c[], int left, int right, int val) // function used to determine the pivot point for quickSort also does the swaping
{
    aCard x;                                           // Temporary variable x to hold cards during sorting
    int count = 0;

    for (int i = left+1; i <= right; i++)                      // 
    {
        if (corOrder(c[i], c[left], val) == 1)
        {
            swap(c[i], c[left]);
            sortCounter++;                       // sort counter increments yet again
        }
    }

    return left;
}

aCard* quickSort(aCard c[], int left, int right, bool val)
{
    if (left >= right) return c;
    int piv;

    piv = partition(c, left, right, val);
    
    quickSort(c, left, (piv-1), val);
    quickSort(c, (piv+1), right, val);
    return c;
}

void printPack(aCard c[], string msg)
{
    string suteNames[] = {"♥️ Hearts", "♣️ Clubs", "♦️ Diamonds", "♠️ Spades"};
    string cardValue[] = {"-", "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

    cout << msg << "\n" << endl;

    for (int i=0; i < maxCard; i++)
    {
        cout << cardValue[c[i].cardVal] << " of " << suteNames[c[i].cardSuit] << endl;
    }

    cout << "------------------------------------------\n" << corOrderCounter << " number of checks. \n" << sortCounter << " moves for " << maxCard << " cards." << "\n------------------------------------------\n" << endl;
}

string testSortingAlgos(aCard a[], aCard b[]){
    for (int i = 0; i < maxCard; i++)
    {
        if ((corOrder(a[i-maxCard], b[i],1)==1) && (corOrder(a[i-maxCard], b[i], 0)==1))
        {
            return "PASSED";
        }
    }
    return "FAILED";
}

int main()
{
    cout << "Card Sorting!\n";

    for (int ct = 0; ct < maxCard; ct++)
    {
        thePack[ct] = getCard("30021591");   // change to your student number
    }

    printPack( thePack, "Your card are: ");

    aCard* bubbleSortedCards;
    aCard* quickSortedCards;
    
    bubbleSortedCards = bubbleSort(thePack, 1);
    bubbleSortedCards = bubbleSort(bubbleSortedCards, 0);
    printPack(bubbleSortedCards, "Bubble Sorted card are: ");

    sortCounter = 0;
    corOrderCounter = 0;

    quickSortedCards = quickSort(thePack, 0, (maxCard-1), 1);
    quickSortedCards = quickSort(quickSortedCards, 0, (maxCard-1), 0);
    printPack(quickSortedCards, "Quick Sorted card are: ");

    // test that Bubble and Quick sort are the same order
    cout << "Test that Bubble sort is the same order as Quick sort: " << testSortingAlgos(bubbleSortedCards, quickSortedCards) << endl;
}
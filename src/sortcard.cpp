// SortCard.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "cardlib.h"

#include <string>
#include <iostream>
using namespace std;

const int maxCard = 3;

aCard thePack[maxCard];

int main()
{
    cout << "Card Sorting!\n";

    for (int ct = 0; ct < maxCard; ct++)
        thePack[ct] = getCard("14398132");   // change to your student number
}




#include <string>
#include <iostream>
using namespace std;
#include "cardlib.h"

struct cardTreeNode {
    aCard card;
    cardTreeNode* less, * more; 
};

cardTreeNode* cardNewNode(cardTreeNode* l, aCard a) {       // create a new node with data s, return pointer to it
    cardTreeNode* pos = new cardTreeNode;     // create space for node
    pos->card = a;                    // add data
    pos->less = NULL;                 // pointers less and more are set to NULL
    pos->more = NULL;
    return pos;                       // return pointer to this new node 
}

int cfstring(aCard c1, aCard c2) {
    // compares two strings : returns -1,0,1
    if (c1.cardVal <= c2.cardVal) return -1;
    else if (c1.cardVal >= c2.cardVal) return 1;
    else return 0;
}

cardTreeNode *insertTree(cardTreeNode* l, aCard a) {
    // insert string s searching from node p, returns pointer to this node (normally unchanged)
    cardTreeNode* ans = l;
    if (l == NULL) ans = cardNewNode(l, a);    // if found NULL pointer, create new node and this is returned connecting to node above
    else if (cfstring(l->card, a) >= 0) l->less = insertTree(l->less, a);    // insert in less subtree
    else if (cfstring(l->card, a) <= 0) l->more = insertTree(l->more, a);    // insert in more subtree
        // change above line if want repeat items in tree
    return ans;         // return pointer to new node, or to this node, as appropriate
}

void printTree(cardTreeNode* l){
    if (l == NULL) return;
    string suteNames[] = {"♥️ Hearts", "♣️ Clubs", "♦️ Diamonds", "♠️ Spades"};
    string cardValue[] = {"-", "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    printTree(l->less);
    // then recur on right subtree

    printTree(l->more);
    // now deal with the node
    cout << cardValue[l->card.cardVal] << " of " << suteNames[l->card.cardSuit] << endl;
}

int main(){
    struct cardTreeNode* stack = NULL;
    aCard c;
    for(int i = 0; i < 10; i++)
    {
        c = getCard("30021591");
        stack = insertTree(stack, c);
    }
    printTree(stack);
    return 0;
}
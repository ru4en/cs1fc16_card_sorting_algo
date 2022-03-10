// BinaryTree.cpp : 
// This has functions to create and print a binary sorted tree of names.
// Prof Richard Mitchell  20/01/22
//

#include <string>
#include <iostream>
using namespace std;

// structure for a node in a binary sorted tree
struct treeNode {
    string data;                     // actual data
    treeNode* less, * more;          // pointers to node with data less or more than in this node
};

treeNode* treeTop;                  // pointer to top of tree

treeNode* newNode(string s) {       // create a new node with data s, return pointer to it
    treeNode* p = new treeNode;     // create space for node
    p->data = s;                    // add data
    p->less = NULL;                 // pointers less and more are set to NULL
    p->more = NULL;
    return p;                       // return pointer to this new node 
}

void printTree(treeNode* p) {   // print the tree from node p
    if (p != NULL) {
        printTree(p->less);             // print any nodes in less sub tree
        cout << p->data << ", ";        // print this node
        printTree(p->more);             // print any nodes in more sub tree
    }
}

int cfstring(string s1, string s2) {
    // compares two strings : returns -1,0,1
    if (s1 < s2) return -1;
    else if (s1 > s2) return 1;
    else return 0;
}

treeNode *insertTree(treeNode* p, string s) {
    // insert string s searching from node p, returns pointer to this node (normally unchanged)
    treeNode* ans = p;
    if (p == NULL) ans = newNode(s);    // if found NULL pointer, create new node and this is returned connecting to node above
    else if (cfstring(p->data, s) > 0) p->less = insertTree(p->less, s);    // insert in less subtree
    else if (cfstring(p->data, s) < 0) p->more = insertTree(p->more, s);    // insert in more subtree
        // change above line if want repeat items in tree
    return ans;         // return pointer to new node, or to this node, as appropriate
}

int main()
{
    cout << "RJM's Tree Program!\n";

    treeTop = NULL;                             // initially an empty tree

    treeTop = insertTree(treeTop, "fred");      // now add names
    treeTop = insertTree(treeTop, "alice");
    treeTop = insertTree(treeTop, "sally");
    treeTop = insertTree(treeTop, "bert");
    treeTop = insertTree(treeTop, "zak");
    treeTop = insertTree(treeTop, "hassan");
    treeTop = insertTree(treeTop, "jiang");

    printTree(treeTop);                         // and print
    cout << "\n";
}

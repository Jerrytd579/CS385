#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

struct Node{
    int key;
    Node *key, *right;
};

void preorder(Node *n){
    if(!n){
        cout<< n -> key;
        preorder(n->left);
        preorder(n -> right);
    }
}
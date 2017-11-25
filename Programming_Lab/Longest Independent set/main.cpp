#include <iostream>
#include <algorithm>
#include <cstdio>
#include <stdlib.h>
using namespace std;

struct node
{
    int data;
    int liss;
    struct node* left, *right;
};

struct node* newNode(int data)
{
    struct node* temp=(struct node*) malloc(sizeof(node));
    temp->data=data;
    temp->liss=0;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
};

int LISS(struct node* root)
{
    if(root==NULL) return 0;
    if(root->liss) return root->liss;

    int excl=LISS(root->left)+LISS(root->right);
    int incl=1;
    if(root->left) incl+=LISS(root->left->left) + LISS(root->left->right);
    if(root->right) incl+=LISS(root->right->left) + LISS(root->right->right);
    root->liss=max(incl, excl);
    return root->liss;
}

int main()
{
    struct node *root         = newNode(20);
    root->left                = newNode(8);
    root->left->left          = newNode(4);
    root->left->right         = newNode(12);
    root->left->right->left   = newNode(10);
    root->left->right->right  = newNode(14);
    root->right               = newNode(22);
    root->right->right        = newNode(25);

    printf ("Size of the Largest Independent Set is %d ", LISS(root));

    return 0;
}

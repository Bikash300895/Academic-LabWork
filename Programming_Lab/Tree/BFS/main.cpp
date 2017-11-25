#include<iostream>
#include<queue>
using namespace std;

struct BstNode
{
    int data;
    BstNode* left;
    BstNode* right;
};

BstNode *GetNewNode(int data)
{
    BstNode* newNode=new BstNode();
    newNode->data=data;
    newNode->left=newNode->right=NULL;
    return newNode;
}

BstNode* Insert(BstNode* root, int data)
{
    if(root==NULL)
    {
        root=GetNewNode(data);
    }
    else if(data<=root->data)
    {
        root->left=Insert(root->left,data);
    }
    else
        root->right=Insert(root->right,data);

    return root;
}

bool Search(BstNode* root, int data)
{
    if(root==NULL) return false;
    else if(root->data==data) return true;
    else if(data<root->data) Search(root->left,data);
    else Search(root->right,data);
}

int Findmin(BstNode* root)
{
    BstNode* current=root;
    while(current->left!=NULL)
    {
        current=current->left;
    }
    return current->data;
}

int FindHight(BstNode* root)
{
    if (root==NULL) return -1;
    return max(FindHight(root->left),FindHight(root->right))+1;
}

void LebelOrder(BstNode* root)
{
    if(root==NULL) return;
    queue <BstNode *> Q;
    Q.push(root);

    while(!Q.empty())
    {
        BstNode* current=Q.front();
        cout<<current->data<<" ";
        if(current->left!=NULL) Q.push(current->left);
        if(current->right!=NULL) Q.push(current->right);
        Q.pop();
    }
}

void InOrder(BstNode* root)
{
    if(root==NULL) return;
    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
}

bool IsLesser(BstNode* root, int value)
{
    if(root==NULL) return true;
    if(root->data<=value && IsLesser(root->left,value) && IsLesser(root->right,value))
        return true;
    else return false;
}

bool IsGreater(BstNode* root, int value)
{
    if(root==NULL) return true;
    if(root->data>value && IsGreater(root->left,value) && IsGreater(root->right,value))
        return true;
    else return false;
}


bool IsBst(BstNode* root)
{
    if(root==NULL) return true;
    if (IsLesser(root->left,root->data)&&IsGreater(root->right,root->data)&&IsBst(root->left)&&IsBst(root->right))
        return true;
    else return false;
}


int main()
{
    BstNode *root=NULL;
    root=Insert(root,15);
    root=Insert(root,5);
    root=Insert(root,10);
    root=Insert(root,20);
    root=Insert(root,25);
    root=Insert(root,35);
    root=Insert(root,30);
    root=Insert(root,10);
    if(IsBst(root)==true)
    {
        cout<<"Bst";
    }
    else cout<<"Not";
}

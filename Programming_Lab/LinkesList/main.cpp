#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* head;

void insertAtBegin(int a)
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node*));
    temp->data=a;
    temp->next=NULL;

    if(head!=NULL) temp->next=head;
    head=temp;
}

void insertAtEnd(int a)
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node*));
    Node *temp1=head;
    temp->data=a;
    temp->next=NULL;

    if(head==NULL)
    {
        head=temp;
        return;
    }

    while(temp1->next!=NULL)
    {
        temp1=temp1->next;
    }

    temp1->next=temp;
}

void show()
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main()
{
    head=NULL;
    cout<<"Enter a number: ";
    int n,a;
    /*insertAtEnd(5);
    insertAtEnd(7);
    show();*/
    cin>>n;
    cout<<"Enter number to enter: ";
    for(int i=0; i<n; i++)
    {
        cin>>a;
        insertAtBegin(a);
    }
    show();
}

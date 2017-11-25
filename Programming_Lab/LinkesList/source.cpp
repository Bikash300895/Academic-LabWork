#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* head;
void Insert_at_begining(int x);
void Print();
void Insert_at_end(int x);
void Insert(int x, int y);
void Search(struct Node* temp,int key, int n);


int main()
{
    head = NULL;
    int n,x,i;
    Insert_at_begining(1);
    Insert_at_begining(2);
    Insert_at_begining(1);
    Insert_at_begining(5);
    Insert_at_begining(9);
    Search(head,1,1);
}

void Insert_at_begining(int x)
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node*));
    temp->data=x;
    temp->next=NULL;

    if(head!=NULL) temp->next=head;
    head=temp;
}

void Insert_at_end(int x)
{
    struct Node* temp1=(struct Node*)malloc(sizeof(struct Node*));
    temp1->data=x;
    temp1->next=NULL;

    if(head==NULL)
    {
        head=temp1;
        return;
    }

    struct Node* temp2=head;
    while(temp2->next!=NULL)
    {
        temp2=temp2->next;
    }
    temp2->next=temp1;
}

void Print()
{
    struct Node* temp=head;
    printf("List is: ");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void Insert(int x, int y)
{
    struct Node* temp1=(struct Node*)malloc(sizeof(struct Node*));
    temp1->data=x;
    temp1->next=NULL;

    if(y==1)
    {
        temp1->next=head;
        head=temp1;
        return;
    }

    int i;
    struct Node* temp2=head;
    for(i=0; i<y-2; i++)
    {
        temp2=temp2->next;
    }
    temp1->next=temp2->next;
    temp2->next=temp1;
}

void Search(struct Node* temp,int key, int n)
{
    if(temp->data==key)
    {
        printf("Found at position: %d\n",n);
    }
    if(temp->next==NULL)
    {
        return;
    }
    Search(temp->next,key,n+1);
}

void RPrint(struct Node* p)
{
    if(p==NULL) return;
    RPrint(p->next);
    printf("%d ",p->data);
}


void Reverse()
{
    struct Node* prev, *current, *next;
    current = head;
    prev=NULL;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
}


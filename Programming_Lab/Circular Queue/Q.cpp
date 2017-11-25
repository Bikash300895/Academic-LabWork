#include<iostream>
using namespace std;
#define MAX_SIZE 3




int A[MAX_SIZE];
int frnt=-1, rear=-1;



int IsEmpty()
{
    if (frnt == -1 && rear ==-1) return 1 ;
    else return 0;
}


int IsFull()
{

    if ((rear+1)%MAX_SIZE == frnt) return 1 ;
    else return 0;
}


void Enqueue(int x)
{
    cout<<"Enqueuing: "<<x<<" \n";
    if(IsFull())
    {
        cout<<"Error: Queue is Full\n";
        return;
    }
    if (IsEmpty())
    {
        frnt = rear = 0;
    }
    else
    {
        rear = (rear+1)%MAX_SIZE;
    }
    A[rear] = x;
}

void Dequeue()
{
    cout<<"Dequeuing \n";
    if(IsEmpty())
    {
        cout<<"Error: Queue is Empty\n";
        return;
    }
    else if(frnt == rear )
    {
        rear = frnt = -1;
    }
    else
    {
        frnt = (frnt+1)%MAX_SIZE;
    }
}

int Front()
{
    if(frnt == -1)
    {
        cout<<"Error: cannot return front from empty queue\n";
        return -1;
    }
    return A[frnt];
}

void print()
{

    int count = (rear+MAX_SIZE-frnt)%MAX_SIZE + 1;
    cout<<"Queue       : ";
    for(int i = 0; i <count; i++)
    {
        int index = (frnt+i) % MAX_SIZE;
        cout<<A[index]<<" ";
    }
    cout<<"\n\n";
}

int main()
{
    while(1)
    {
        cout<<"1.Enqueue"<<endl;
        cout<<"2.deq"<<endl;
        cout<<"3.Exit"<<endl;

        int a;

        cin>>a;

        if(a==1)
        {
            cout<<"enter value:";

            int b;

            cin>>b;
            Enqueue(b);
            print();
            Front();
        }
        else if(a==2)
        {
            Dequeue();

            if(IsEmpty());
            else  print();
        }
        else break;
    }
}

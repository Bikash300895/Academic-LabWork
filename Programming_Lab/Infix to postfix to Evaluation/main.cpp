#include <iostream>
#include <stdio.h>
#include <cstring>
#include <ctype.h>
using namespace std;

char prefix[100]="";
char postfix[100]="";
char stack[100]="";
int p=-1,s=-1;

int Stack1[50];
int top = -1;

void push(int c) {
    top++;
    Stack1[top] = c;
}

int pop() {
    int c = Stack1[top];
    Stack1[top] = 0;
    top--;
    return c;
}

int Operator(char x) {
    switch(x) {
    case '+':
        return -1;
    case '-':
        return -2;
    case '*':
        return -3;
    case '/':
        return -4;
    case '^':
        return -5;
    default:
        return 0;
    }
}

void evaluation(char *s) {
    char ara[50], x1, x2;
    int i, j, len;

    len = strlen(s);
    for(i=0; i<len; i++) {
        int x, sum=0;
        while(isdigit(s[i])) {
            x = s[i]-'0';
            sum = 10*sum+x;
            i++;
        }
        if(sum!=0) push(sum);

        if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || s[i]=='^') {
            if(Operator(s[i])==-1)
                Stack1[top-1] = Stack1[top-1] + Stack1[top];
            else if(Operator(s[i])==-2)
                Stack1[top-1] = Stack1[top-1] - Stack1[top];
            else if(Operator(s[i])==-3)
                Stack1[top-1] = Stack1[top-1] * Stack1[top];
            else if(Operator(s[i])==-4)
                Stack1[top-1] = Stack1[top-1] / Stack1[top];
            else if(Operator(s[i])==-5)
                Stack1[top-1] = Stack1[top-1] ^ Stack1[top];

            pop();
        }

    }

}

void pushInPostfix(char c)
{
    p++;
    postfix[p]=c;
    p++;
    postfix[p]=' ';
}

void pushInStack(char c)
{
    s++;
    stack[s]=c;
}

void popFromStack()
{
    s--;
}

int main()
{
    cout<<"Enter the prefix exprasion: "<<endl;
    cin>>prefix;
    for(int i=0; prefix[i]!='\0'; i++)
    {
        while(prefix[i]>='0' && prefix[i]<='9')
        {
            //pushInPostfix(prefix[i]);
            p++;
            postfix[p]=prefix[i];
            i++;
        }
        p++;
        postfix[p]=' ';


        if(prefix[i]=='(' || prefix[i]=='^')
            pushInStack(prefix[i]);
        else if(prefix[i]=='*' || prefix[i]=='/')
        {
            if(stack[s]=='^')
            {
                pushInPostfix(stack[s]);
                popFromStack();
                pushInStack(prefix[i]);
            }
            else
            {
                pushInStack(prefix[i]);
            }
        }

        else if(prefix[i]=='+' || prefix[i]=='-')
        {
            if(stack[s]=='^'||stack[s]=='/'||stack[s]=='*')
            {
                pushInPostfix(stack[s]);
                popFromStack();
                pushInStack(prefix[i]);
            }
            else
            {
                pushInStack(prefix[i]);
            }
        }
        else if(prefix[i]==')')
        {
            while(stack[s]!='(')
            {
                pushInPostfix(stack[s]);
                popFromStack();
            }
            popFromStack();
        }
    }
    while(s!=-1)
    {
        pushInPostfix(stack[s]);
        popFromStack();
    }
    postfix[p]='\0';
    cout<<postfix<<endl;

    evaluation(postfix);
    cout<<Stack1[0]<<endl;

}

//1+(2*3-(4/5^6)*7)*8

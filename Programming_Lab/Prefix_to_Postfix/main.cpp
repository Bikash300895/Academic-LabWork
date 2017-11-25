#include <bits/stdc++.h>

using namespace std;

string intopost(string);
bool isgreater(char,char);
int getweight(char);
bool isoperator(char);
bool isoperand(char);

stack<char> s;

int main()
{
    cout<<"Inter expression"<<endl;
    string infix;
    cin>>infix;
    string postfix=intopost(infix);
    cout<<postfix<<endl;



}

string intopost(string infix)
{
    string postfix="";
    for(int i=0; i<infix.length(); i++)
    {

        if(isoperand(infix[i]))
        {
            postfix+=infix[i];
        }
        else if(isoperator(infix[i]))
        {
            while(!s.empty() && s.top()!='(' && isgreater(infix[i],s.top()))
            {
                postfix+= s.top();
                s.pop();

            }
            s.push(infix[i]);


        }
        else if (infix[i] == '(')
        {
            s.push(infix[i]);
        }

        else if(infix[i] == ')')
        {
            while(!s.empty() && s.top() !=  '(')
            {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }
    }

    while(!s.empty())
    {
        postfix += s.top();
        s.pop();
    }
    return postfix;
}








bool isoperator(char C)
{
    if(C == '+' || C == '-' || C == '*' || C == '/' || C== '^')
        return true;

    return false;
}

bool isoperand(char C)
{
    if(C >= '0' && C <= '9') return true;
    if(C >= 'a' && C <= 'z') return true;
    if(C >= 'A' && C <= 'Z') return true;
    return false;
}

int getweight(char op)
{
    if(op=='+' || op =='-')
        return 1;

    if(op=='*' || op =='/')
        return 2;

    if(op=='#')
        return 3;
}

bool isgreater(char op1, char op2)
{
    int op1Weight = getweight(op1);
    int op2Weight = getweight(op2);

    return op1Weight < op2Weight ?  true: false;
}

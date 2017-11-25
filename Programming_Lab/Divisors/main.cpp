#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;



int mark[1000002];
vector <int> divisors[1000002];

void Divisor(int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=i;j<n; j+=i)
        {
            divisors[j].push_back(i);
        }
    }
}

int main()
{
    Divisor(100);
    int i;
    int n;
    cin>>n;
    for(i=0; i<divisors[n].size(); i++)
    {
        cout<<divisors[n].back()<<" ";
    }
}

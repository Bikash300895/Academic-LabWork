#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

int x=0;
using namespace std;

void InsertionSort(int A[],int n)
{
    int i;
    for(i=1; i<n; i++)
    {
        int hole=i;
        int value=A[i];

        while(hole>0&&A[hole-1]>value)
        {
            A[hole]=A[hole-1];
            hole=hole-1;
        }
        A[hole]=value;
    }
}

int main()
{
    int c,s;
    while(scanf("%d %d",&c,&s))
    {
        x++;
        int n=2*c,i,j;
        double imb=0.0,ave=0.0;
        int a[n];
        i=0;
        for(i=0; i<s; i++)
        {
            scanf("%d",&a[i]);
            ave+=a[i];
        }
        ave/=c;
        for(;i<n; i++)
        {
            a[i]=0;
        }
        InsertionSort(a,n);

        int k=0,l=n-1;
        vector<int> b[c];
        double d[c];
        for(i=0; i<c; i++)
        {
            d[i]=0;
        }
        for(i=0; i<c; i++)
        {
            if(a[k]!=0)
            {
                b[i].push_back(a[k]);
                d[i]+=a[k];
            }

            if(a[l]!=0)
            {
                b[i].push_back(a[l]);
                d[i]+=a[l];
            }
            if(d[i]>ave)
            {
                d[i]=d[i]-ave;
            }
            else d[i]=ave-d[i];
            k++;
            l--;
        }
        printf("set #%d\n",x);
        for(i=0; i<c; i++)
        {
            printf(" %d:",i);
            for(j=0;j<b[i].size(); j++)
            {
                printf(" %d",b[i][j]);
            }
            printf("\n");
        }
        for(i=0; i<c ;i++)
        {
            imb+=d[i];
        }
        printf("IMBALANCE = %.5lf",imb);
    }
}

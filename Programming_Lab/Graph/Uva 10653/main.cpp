#include <iostream>
#include <algorithm>
#include <queue>
#include <math.h>
#include <cstring>
#define INF 1000000;
using namespace std;

int R,C;
queue <int> q;
int matrix[1001][1001];

void reset()
{
    for(int i=0; i<1001; i++)
        memset(matrix[i],-1,sizeof(matrix[i]));
}

bool valid (int r, int c)
{
    if(r>=0&&r<=R&&c>=0&&c<=C) return true;
    return false;
}

void insert(int r, int c, int val)
{
    matrix[r][c]=val+1;
    q.push(r);
    q.push(c);
}

int main()
{
    while(cin>>R>>C)
    {
        if(R==0&&C==0) break;
        reset();
        int r;
        cin>>r;
        for(int i=0; i<r; i++)
        {
            int rowNumber;
            cin>>rowNumber;
            int mines;
            cin>>mines;
            int pos;
            for(int j=0; j<mines; j++)
            {
                cin>>pos;
                matrix[rowNumber][pos]=INF;
            }
        }
        int sourceR, sourceC, destR, destC;
        cin>>sourceR>>sourceC>>destR>>destC;

        matrix[sourceR][sourceC]=0;
        q.push(sourceR);
        q.push(sourceC);

        while(!q.empty())
        {
            int row, col;
            row=q.front(); q.pop();
            col=q.front(); q. pop();

            if(valid(row-1, col)&& matrix[row-1][col]<0)
                insert(row-1,col,matrix[row][col]);
            if(valid(row, col+1)&& matrix[row][col+1]<0)
                insert(row,col+1,matrix[row][col]);
            if(valid(row+1, col)&& matrix[row+1][col]<0)
                insert(row+1,col,matrix[row][col]);
            if(valid(row, col-1)&& matrix[row][col-1]<0)
                insert(row,col-1,matrix[row][col]);

        }
        cout<<matrix[destR][destC]<<endl;
    }
    return 0;
}

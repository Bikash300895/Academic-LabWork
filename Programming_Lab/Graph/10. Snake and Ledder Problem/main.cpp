#include <iostream>
#include <queue>
using namespace std;

struct queueEntry
{
    int v;
    int dist;
};

int getMinDiceThrows(int move[], int n)
{
    bool *visited=new bool[n];
    for(int i=0; i<n; i++)
        visited[i]=false;

    queue<queueEntry> q;

    visited[0]=true;
    queueEntry s={0,0};
    q.push(s);

    queueEntry qe;
    while(!q.empty())
    {
        qe=q.front();
        int v=qe.v;

        if(v==n-1) break;
        q.pop();
        for(int j=v+1; j<=(v+6)&& j<n; j++)
        {
            if(!visited[j])
            {
                queueEntry a;
                a.dist=(qe.dist+1);
                visited[j]=true;

                if(move[j]!=-1) a.v=move[j];
                else a.v=j;

                q.push(a);
            }
        }
    }
    return qe.dist;
}

int main()
{
    int n=30;
    int moves[30];
    for(int i=0; i<n; i++)
        moves[i]=-1;

    moves[2]=21;
    moves[4]=7;
    moves[10]=25;
    moves[19]=28;

    moves[26]=0;
    moves[20]=8;
    moves[16]=3;
    moves[18]=6;

    cout<<getMinDiceThrows(moves,n);
    return 0;
}

#include <iostream>
#include <vector>
#include <stdio.h>


using namespace std;

int main()
{
    int n;
    int set=1;
    while(scanf("%d",&n) && n)
    {
        int brick;
        int media=0;
        int moves=0;
        vector <int> bricks;

        for(int i=0; i<n; i++)
        {
            int brick;
            cin>>brick;
            media+=brick;
            bricks.push_back(brick);
        }

        media/=n;
        for(int i=0; i<n ;i++)
        {
            if(bricks[i]>media)
            {
                moves+=bricks[i]-media;
            }
        }
        cout<<"Set #"<<set<<endl;
        cout<<"The minimum number of moves is "<<moves;
        set++;
    }
    return 0;
}

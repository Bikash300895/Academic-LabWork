#include <iostream>

using namespace std;

bool isleap(int y)
{
    if(y%4==0)
    {
        if(y%400==0)
            return true;
        else if(y%100==0)
            return false;
        return true;
    }
    return false;
}


int main()
{
    int y;
    cin>>y;
    int sum=0;
    if(!isleap(y))
    {
        for(int i=0;i<14;i++)
        {
            if(isleap(y))
                sum+=2;
            else
                sum+=1;
            if(sum%7==0)
            {
                cout<<++y<<endl;
                return 0;
            }
            y++;
        }
    }

   /* if(!isleap(y))
    {

        if(y%4==0)
            cout<<y+6<<endl;
        else if(y%4==1)
            cout<<y+6<<endl;
        else if(y%4==2)
            cout<<y+11<<endl;
        else if(y%4==3)
            cout<<y+11<<endl;
    }*/
    else
        cout<<y+28<<endl;
}

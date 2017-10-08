#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream f("input.txt");
    int p, r;
    //cout<<"Enter the number of process and resources ";
    f >> p >> r;
    //cout<<p<<r;

    int allocation[p][r];
    int maximum[p][r];
    int need[p][r];
    int avaiable[r];
    bool isServed[p];
    int servedSeq[p];
    int servedIndex = 0;

    for(int i=0; i<p; i++)
    {
        isServed[i] = false;
    }

    //taking the values of initial available of the resources
    for(int i=0; i<r; i++){
        f>>avaiable[i];
    }


    // taking value for allocations
    for(int i=0; i<p; i++)
    {
        for(int j=0; j<r; j++)
        {
            f>>allocation[i][j];
        }
    }

    //taking values for maximum
    for(int i=0; i<p; i++)
    {
        for(int j=0; j<r; j++)
        {
            f>>maximum[i][j];
        }
    }

    // calculating current available
    for(int i=0; i<p; i++){
        for(int j=0; j<r; j++){
            avaiable[j] -= allocation[i][j];
        }
    }

    while(true)
    {
        bool someOneServed = false;

        for (int i=0; i<p; i++)
        {
            if(isServed[i] == false)
            {
                // calculate need
                for(int j=0; j<r; j++)
                {
                    need[i][j] = maximum[i][j] - allocation[i][j];

                }

                // check if all need are enough
                bool servable = true;
                for (int j=0; j<r; j++)
                {
                    if(need[i][j] > avaiable[j])
                    {
                        servable = false;
                        break;
                    }
                }

                // if served free the resource
                if(servable)
                {
                    servedSeq[servedIndex] = i;
                    servedIndex++;

                    someOneServed = true;
                    isServed[i] = true;
                    for(int j=0; j<r; j++)
                    {
                        avaiable[j] += allocation[i][j];
                    }
                }
            }

        }

        bool allServed = true;
        for (int i=0; i<p; i++)
        {
            if (isServed[i] == false)
            {
                allServed = false;
            }
        }

        if(allServed)
        {
            for(int k=0; k<p; k++){
                cout<<servedSeq[k]<<" -> ";
            }

            cout<<"The system is in safe state"<<endl;
            return 0;
        }

        if(someOneServed==false)
        {
            cout<<"The system in not in safe state"<<endl;
            return 0;
        }

    }

    return 0;

    for(int i=0; i<p; i++)
    {
        for(int j=0; j<r; j++)
        {
            cout<<maximum[i][j]<<" ";
        }
        cout<<endl;
    }



    for(int i=0; i<p; i++)
    {
        for(int j=0; j<r; j++)
        {
            cout<<allocation[i][j]<<" ";
        }
        cout<<endl;
    }


}

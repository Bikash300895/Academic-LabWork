#include <iostream>
#include <string>
#include "Creature.h"
#include "Point2D.h"
using namespace std;

int main()
{
    cout<<"Enter a name of Creature: ";
    string cName;
    cin>>cName;
    Creature cCreature(cName, Point2D(4,7));

    while(1)
    {
        cout<<cCreature<<endl;
        cout<<"Enter new X location: ";
        int nx;
        cin>>nx;
        if(nx==-1)
            break;

        cout<<"Enter new Y location: ";
        int ny;
        cin>>ny;
        if(ny==-1)
            break;

        cCreature.MoveTo(nx,ny);
    }
}

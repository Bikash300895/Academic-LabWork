#ifndef CREATURE_H_INCLUDED
#define CREATURE_H_INCLUDED

#include <iostream>
#include <string>
#include "Point2D.h"
using namespace std;

class Creature
{
private:
    string m_strName;
    Point2D m_cLocation;
public:
    Creature(string strName, const Point2D &cLocation)
    {
        m_strName=strName;
        m_cLocation=cLocation;
    }

    friend ostream& operator<<(ostream& out, const Creature &cCreature)
    {
        out<<cCreature.m_strName<<"is at"<<cCreature.m_cLocation;
        return out;
    }

    void MoveTo(int nx, int ny)
    {
        m_cLocation.SetPoint(nx,ny);
    }
};

#endif // CREATURE_H_INCLUDED

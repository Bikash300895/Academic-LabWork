#ifndef POINT2D_H_INCLUDED
#define POINT2D_H_INCLUDED

#include <iostream>
using namespace std;

class Point2D
{
private:
    int m_nX;
    int m_nY;
public:
    Point2D():m_nX(0),m_nY(0)
    {

    }
    Point2D(int nx, int ny):m_nX(nx),m_nY(ny)
    {

    }

    int GetX() const
    {
        return m_nX;
    }

    int GetY() const
    {
        return m_nY;
    }

    void SetPoint(int nx, int ny)
    {
        m_nX=nx;
        m_nY=ny;
    }

    friend ostream& operator<<(ostream& out, const Point2D& cPoint)
    {
        out<<"("<<cPoint.GetX()<<","<<cPoint.GetY()<<")";
        return out;
    }
};


#endif // POINT2D_H_INCLUDED

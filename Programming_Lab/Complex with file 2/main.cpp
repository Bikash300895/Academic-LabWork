#include <iostream>
#include <fstream>
using namespace std;

ifstream file("input.txt");

class M
{
public:
    class N
    {
    public:
        int r;
        int i;
    };
    N m[2][2];
    M operator*(M);
};

istream & operator >> (istream &in,M &m_)
{
    for(int a=0;a<2;a++)
        for(int b=0;b<2;b++)
            file >> m_.m[a][b].r >> m_.m[a][b].i;
    return in;
}

ostream & operator << (ostream &oute,M &m_)
{
    ofstream out("output.txt");
    for(int a=0;a<2;a++)
    {
        for(int b=0;b<2;b++)
        {
            if(m_.m[a][b].i<0)
                out << m_.m[a][b].r << " - "<< 0-m_.m[a][b].i << "i" << "       ";
            else if(m_.m[a][b].i==0)
                out << m_.m[a][b].r << "               ";
            else
                out << m_.m[a][b].r << " + "<< m_.m[a][b].i << "i" << "        ";
        }
        cout << endl;
    }
    return oute;
}

M M::operator*(M m_)
{
    M m__;
    for(int a=0;a<2;a++)
        for(int b=0;b<2;b++)
        {
            m__.m[a][b].r=m_.m[a][b].r*m[a][b].r;
            m__.m[a][b].i=m_.m[a][b].i*m[a][b].i;
        }
    return m__;
}
int main()
{
    M m1,m2,m3;
    //cout<<"Matrix 1"<<endl;
    cin>>m1;
    //cout<<"Matrix 2"<<endl;
    cin>>m2;
    cout<<"Multiplication Succeed"<<endl;
    m3=m1*m2;
    cout<<m3<<endl;
    return 0;
}


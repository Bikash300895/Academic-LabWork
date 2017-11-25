#include <iostream>

using namespace std;
class Matrix
{
    int data[10][10];
    int r;
    int c;
public:
    friend istream& operator>>(istream& in, Matrix& matrix)
    {
        cout<<"row :";
        cin>>matrix.r;
        cout<<"col :";
        cin>>matrix.c;

        for(int i=0; i<matrix.r; i++)
        {
            for(int j=0; j<matrix.c; j++)
            {
                cout<<i<<" "<<j<<" :";
                in>>matrix.data[i][j];

            }
        }
        return in;

    }

    friend ostream& operator<<(ostream& out, Matrix& matrix)
    {

        for(int i=0; i<matrix.r; i++)
        {
            for(int j=0; j<matrix.c; j++)
            {
                out<<matrix.data[i][j]<<" ";

            }
            out<<endl;
        }
        return out;
    }


public:

    class Proxy
    {
        int *p;
    public:
        Proxy(int *p):p(p) {}
        int operator[](int i2)
        {
            return p[i2];
        }

    };


    Proxy operator[](int i1)
    {
        Proxy prox(&data[i1][0]);
        return prox;

    }

};
int main()
{
    Matrix a1;
    cin>>a1;
    cout<<a1;
    cout<<a1[1][1];

    return 0;
}

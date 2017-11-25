#include <iostream>
using namespace std;
class matrix {
    int row,col,mat[5][5];
public:
    matrix()
    {
        row=col=0;
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
            {
                mat[i][j]=0;
            }
        }
    }
    ~matrix()
    {
        delete mat;
    }
    friend istream& operator >>(istream& din,matrix& m);
    friend ostream& operator <<(ostream& dout,matrix& m);
    matrix operator *(matrix m2);
    int operator !=(matrix m2);
};


istream& operator >>(istream& din,matrix& m)
{
    cout<<"Enter the size"<<endl;
    din>>m.row>>m.col;
    cout<<"Enter the elements"<<endl;
    for(int i=0;i<m.row;i++)
    {
        for(int j=0;j<m.col;j++)
        {
            din>>m.mat[i][j];
        }
    }
    return din;
}


ostream& operator <<(ostream& dout,matrix& m)
{
    for(int i=0;i<m.row;i++)
    {
        for(int j=0;j<m.col;j++)
        {
            dout<<m.mat[i][j]<<"  ";
        }
        dout<<endl;
    }
    return dout;
}
matrix matrix :: operator *(matrix m2)
{
    matrix m3;
    m3.row=m3.col=row;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            m3.mat[i][j];
            for(int k=0;k<m2.row;k++)
            {
                m3.mat[i][j]+=mat[i][k]*m2.mat[k][j];
            }
        }
    }
    return m3;
}
int matrix :: operator !=(matrix m2)
{
    if(row!=m2.row && col!=m2.col)
    {
        return 1;
    }
    else
        return 0;
}
int main()
{
    matrix m1,m2,m3;
    cout<<"Matrix 1"<<endl;
    cin>>m1;
    cout<<"Matrix 2"<<endl;
    cin>>m2;
    if(m1!=m2)
    {
        cout<<"Matrix size needs to be equal"<<endl;
    }
    cout<<"Multiplication"<<endl;
    m3=m1*m2;
    cout<<m3<<endl;
}

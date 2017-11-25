#include<iostream>
#include <cstdlib>
using namespace std;
class complex
{
    public:
    int real;
    int img;
    complex()
    {
        real=0;
        img=0;
    }
    public :
    friend istream& operator>>(istream &in,complex& M)
    {
       in>>M.real>>M.img;
   return in;
    }
    friend ostream& operator<<(ostream &out,complex& M)
    {
    cout<<M.real<<"+"<<M.img<<"i";
    return out;
    }
  friend complex&  operator+(complex &m1,complex &m2);
    friend complex & operator-(complex& m1,complex& m2);
    friend complex & operator*(complex& m1,complex& m2);

};
complex& operator+(complex &m1,complex &m2)

{
    complex M;
    M.real=m1.real+m2.real;
    M.img=m1.img+m2.img;
    return M;
}
complex& operator-(complex &m1,complex &m2)

{
    complex M;
    M.real=m1.real-m2.real;
    M.img=m1.img-m2.img;
    return M;
}
complex& operator*(complex &m1,complex &m2)

{
    complex M;
    M.real=m1.real*m2.real;
    M.img=m1.img*m2.img;
    return M;
}

class Array
{
private:
    complex *p;
public:
    int length;
    Array(int size = 0): length(size)
    {
        p = new complex[length];
    }
    complex& operator [](const int k)
    {
        return p[k];
    }
};

class matrix
{

 public :
     Array* p;
     int r,c;
       matrix(){};
     matrix(int row, int col)
    {
        r=row;
        c=col;
        p=new Array[r];
    }

    Array& operator [](const int& i)
    {
        return p[i];
    }


    friend ostream& operator<<(ostream &out,matrix& M)
{
    for(int i=0;i<M.r;i++){
        for(int j=0;j<M.c;j++){
            out<<M[i][j]<<" ";
        }
        out<<endl;
    }
    return out;
}
friend istream& operator>>(istream  &in,matrix& M)
{
    for(int i=0;i<M.r;i++){
        for(int j=0;j<M.c;j++){
            in>>M[i][j];
        }
    }
    return in;
}

    friend matrix&  operator+(matrix &m1,matrix &m2);
    friend matrix & operator-(matrix& m1,matrix& m2);
    friend matrix & operator*(matrix& m1,matrix& m2);

};

matrix& operator+(matrix &m1 ,matrix &m2)
{
 // matrix temp(m1.r, m1.c);
      matrix M(m1.r, m1.c);

    for(int i=0;i<M.r;i++){
        for(int j=0;j<M.c;j++){
          M[i][j]=m1[i][j]+m2[i][j];
        }
    }
    return M;
}

matrix& operator-(matrix &m1 ,matrix &m2)
{
 // matrix temp(m1.r, m1.c);
      matrix M(m1.r, m1.c);

    for(int i=0;i<M.r;i++){
        for(int j=0;j<M.c;j++){
          M[i][j]=m1[i][j]-m2[i][j];
        }
    }
    return M;
}

matrix& operator*(matrix &m1 ,matrix &m2)
{
 // matrix temp(m1.r, m1.c);
      matrix M(m1.r, m1.c);

    for(int i=0;i<M.r;i++){
        for(int j=0;j<M.c;j++){
          M[i][j]=m1[i][j]*m2[i][j];
        }
    }
    return M;
}

int main()
{
    matrix m1(2,2),m2(2,2),m3(2,2);
    cin>>m1;
    cout<<"1st matrix : \n";
    cout<<m1;
    cout<<endl;
    cin>>m2;
    cout<<endl<<"2nd matrix : \n";
    cout<<m2;
    m3=m1+m2;
    cout<<"ADDITION"<<endl;
    cout<<m3;
    cout<<"SUBSTRACTION"<<endl;
    m3=m1-m2;
    cout<<m3;
    cout<<"MUltipication"<<endl;
    m3=m1*m2;
    cout<<m3;
   return 0;
}

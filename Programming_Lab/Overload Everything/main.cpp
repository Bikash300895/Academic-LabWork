#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
using namespace std;

int r1,i1,r2,i2;
char c;

class Complex
{
    int real;
    int imaginary;
public:
    Complex()
    {
        real=0;
        imaginary=0;
    }
    Complex(int r, int i)
    {
        real=r;
        imaginary=i;
    }
    void show()
    {
        cout<<real<<"+"<<imaginary<<"i"<<endl;
    }
    friend Complex operator+(Complex c1, Complex c2);
    friend Complex operator-(Complex c1, Complex c2);
    friend ostream& operator<<(ostream& out, Complex c3);
    friend istream& operator>>(istream& in, Complex c4);
};

Complex operator+(Complex c1, Complex c2)
{
    Complex c4;
    c4.real=c1.real+c2.real;
    c4.imaginary=c1.imaginary+c2.imaginary;
    return c4;
}

Complex operator-(Complex c1, Complex c2)
{
    Complex c4;
    c4.real=c1.real-c2.real;
    c4.imaginary=c1.imaginary-c2.imaginary;
    return c4;
}

ostream& operator<<(ostream& out, Complex c3)
{
    out<<c3.real<<" + "<<c3.imaginary<<"i"<<endl;
    return out;
}

istream& operator>>(istream& in, Complex c1)
{

    return in;
}

stringstream& operator>>(stringstream& input, string line)
{

   int arr[4];
   int j=0;
   int i=0;
   while(line[i]!='\0')
   {
      if(isdigit(line[i]))
      {
         arr[j]=line[i]-48;
         j++;
      }
      i++;
   }
   //for(int i=0; i<4; i++) cout<<arr[i]<<" ";
   r1=arr[0];
   i1=arr[1];
   r2=arr[2];
   i2=arr[3];

   return input;
}


int main()
{
    ifstream file("input.txt");
    string line;

    while(getline(file,line))
    {
        if(line!="")
        {
            stringstream input(line);
            input>>line;
            Complex c1(r1,i1);
            Complex c2(r2,i2);
            Complex c3;
            c3=c1+c2;
            cout<<c3;
        }

    }

    return 0;
}

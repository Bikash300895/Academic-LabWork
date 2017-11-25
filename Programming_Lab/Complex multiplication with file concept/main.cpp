#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <stdio.h>
using namespace std;

class Matrix
{
public:
    int real[4],img[4];
    friend Matrix operator* (Matrix m1, Matrix m2);

    void Print()
    {
        ofstream out("output.txt");
        out<<real[0]<<"+"<<img[0]<<"i"<<"\t"<<real[1]<<"+"<<img[1]<<"i"<<endl;
        out<<real[2]<<"+"<<img[2]<<"i"<<"\t"<<real[3]<<"+"<<img[3]<<"i"<<endl;
    }
};

Matrix operator*(Matrix m1, Matrix m2)
{
    Matrix m3;
    m3.real[0]=m1.real[0]*m2.real[0];
    m3.real[1]=m1.real[1]*m2.real[1];
    m3.real[2]=m1.real[2]*m2.real[2];
    m3.real[3]=m1.real[3]*m2.real[3];

    m3.img[0]=m1.img[0]*m2.img[0];
    m3.img[1]=m1.img[1]*m2.img[1];
    m3.img[2]=m1.img[2]*m2.img[2];
    m3.img[3]=m1.img[3]*m2.img[3];
    return m3;
}


int main()
{
    Matrix m1,m2,m3;
    ifstream file("input.txt");
    string line;
    char c;


    getline(file,line);
    stringstream ss(line);
    ss>>m1.real[0]>>c>>m1.img[0]>>c>>m1.real[1]>>c>>m1.img[1]>>c>>m2.real[0]>>c>>m2.img[0]>>c>>m2.real[1]>>c>>m2.img[1];
    getline(file,line);
    stringstream s(line);
    s>>m1.real[2]>>c>>m1.img[2]>>c>>m1.real[3]>>c>>m1.img[3]>>c>>m2.real[2]>>c>>m2.img[2]>>c>>m2.real[3]>>c>>m2.img[3];


    m3=m1*m2;
    m3.Print();
    cout<<"Succeed :D"<<endl;

    return 0;
}

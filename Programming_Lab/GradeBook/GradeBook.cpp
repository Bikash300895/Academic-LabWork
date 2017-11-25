#include <iostream>
#include <iomanip>
#include "GradeBook.h"

using namespace std;

GradeBook::GradeBook( string name, const int gradesArray[])
{
    setCourseName(name);

    for(int i=0; i<students; i++)
    {
        grades[i]=gradesArray[i];
    }
}

void GradeBook::setCourseName( string name )
{
    courseName = name;
}

string GradeBook::getCourseName()
{
    return courseName;
}

void GradeBook::displayMessege()
{
    cout<<"Welcome to : "<<endl;
    cout<<getCourseName()<<endl;
}

void GradeBook::processGrade()
{
    outputGrades();
    cout<<"\nClass average is :"<<setprecision(2)<<fixed<<getAverage()<<endl;
    cout<<"Lowest grade is :"<<getMinimum()<<endl;
    cout<<"Hight grade is: "<<getMaximum()<<endl;
    outputGrades();
}

int GradeBook::getMinimum()
{
    int low=100;

    for(int i=0; i<students; i++)
    {
        if(grades[i]<low)
            low=grades[i];
    }
    return low;
}

int GradeBook::getMaximum()
{
    int high=0;

    for(int i=0; i<students; i++)
    {
        if(grades[i]>high)
            high=grades[i];
    }
    return high;
}

double GradeBook::getAverage()
{
    int total=0;
    for(int i=0; i<students; i++)
    {
        total+=grades[i];
    }
    return static_cast<double>(total)/students;
}

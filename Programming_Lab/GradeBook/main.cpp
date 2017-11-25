#include <iostream>
#include <cstring>
#include "GradeBook.h"
using namespace std;

int main()
{
    GradeBook book("Introduction to c++ by Deitel");
    cout<<book.getCourseName();
}

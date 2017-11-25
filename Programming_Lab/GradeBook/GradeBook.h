#include <string>
using namespace std;
class GradeBook
{
private:
    string courseName;
    int grades[students];
public:
    static const int students=10;
    GradeBook( string , const int []);
    void setCourseName( string name);
    string getCourseName();
    void displayMessege();
    void processGrade();
    int getMinimum();
    int getMaximum();
    double getAverage();
    void outputBatChart();
    void outputGrades();
};


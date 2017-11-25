#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED
class date
{
    int day;
    int month;
    int year;
public:
    date(int d, int m, int y);
    void setDate(int d, int m, int y);
    void show();
};
#endif // DATE_H_INCLUDED

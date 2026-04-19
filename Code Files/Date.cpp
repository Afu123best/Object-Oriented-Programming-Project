#include "Date.h"
#include <iostream>
using namespace std;

Date::Date(int d, int m, int y)
{
    day = d;
    month = m;
    year = y;
}
int Date::get_day()
{
    return day;
}
int Date::get_month()
{
    return month;
}
int Date::get_year()
{
    return year;
}
bool Date::is_within_24_hrs(Date& current)
{
    if (current.day == this->day && current.month == this->month && current.year == this->year) //Current: 19/4/2026, this: 19/4/2026
    {
        return true;
    }
    if (current.day - this->day == 1 && current.month == this->month && current.year == this->year) //current: 19/4/2026, this: 18/4/2026
    {
        return true;
    }
    //boundary edge case for months and years  current: 1st may 2026, this: 30th april 2026
    if (current.day == 1)
    {
        int previous_month = current.month - 1;
        int previous_year = current.year;
        if (previous_month == 0)
        {
            previous_month = 12;
            previous_year = current.year - 1;
        } 
        int days_in_month[] = {31,28,31,30,31,30,31,31,30,31,30,31};
        int last_day = days_in_month[previous_month - 1];
        if (this->day == last_day && this->month == previous_month && this->year == previous_year)
        {
            return true;
        }
    }
    return false;
}
void Date::display() // dd/mm/yy
{
    cout << "dd/mm/yy: " << day << "/" << month << "/" << year << endl;
}

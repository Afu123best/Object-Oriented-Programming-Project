#pragma once
class Date
{
private:
    int day, month, year;

public:
    Date(int d, int m, int y);

    int get_day();
    int get_month();
    int get_year();

    bool is_within_24_hrs(Date& current);
    void display();
};
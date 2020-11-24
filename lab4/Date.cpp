#include "Date.h"
#include <iostream>

Date::Date(int dd, int mm, int yy): _day(dd), _month(mm), _year(yy)
{
    if (dd < 1 || dd > 31) 
        throw std::logic_error("bad day argument\n");
    
    if (mm < 1 || mm > 12)
        throw std::logic_error("bad mounth argument\n");
    
    if (yy < 0)
        throw std::logic_error("bad year argument\n");
}


int Date::GetDay() const
{
    return _day;
}

int Date::GetMonth() const
{
    return _month;
}

int Date::GetYear() const
{
    return _year;
}

std::ostream& operator<<(std::ostream& out, const Date& object)
{
    out << object._day << '.' << object._month << '.' << object._year;
    return out;
}
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

Date::Date(): _day(1), _month(1), _year(0) {}
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

bool Date::operator==(const Date& other) const
{
    return (_day == other._day) && (_month == other._month) && (_year == other._year);
}

bool Date::operator!=(const Date& other) const
{
    bool equal = (_day == other._day) && (_month == other._month) && (_year == other._year);
    return !equal;
}

bool Date::operator<(const Date& other) const
{
	int date1 = GetDaysCount();
	int date2 = other.GetDaysCount();

	if (date1 < date2)
	{
		return true;
	}
	return false;
}

bool Date::operator>(const Date& other) const
{
	int date1 = GetDaysCount();
	int date2 = other.GetDaysCount();

	if (date1 > date2)
	{
		return true;
	}
	return false;
}

std::ostream& operator<<(std::ostream& out, const Date& object)
{
    out << object._day << '.' << object._month << '.' << object._year;
    return out;
}
int Date::GetDaysCount() const
{
	int res = _day;

	for (int i = 1; i < _month; i++)
	{
		res += GetDaysCountInMonth(_month, _year);
	}

	int leapYearsCount = _year / 4;
	int yearsCount = _year - leapYearsCount;

	res += leapYearsCount * 366 + yearsCount * 365;

	return res;
}

int Date::GetDaysCountInMonth(int month, int year)
{
	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		return 30;
	}
	else if (month == 2)
	{
		if (GetDaysCountInYear(year) == 365)
		{
			return 28;
		}
		else
		{
			return 29;
		}
	}
	else
	{
		return 31;
	}
}

int Date::GetDaysCountInYear(int year)
{
	if (year % 4 != 0 || year % 100 == 0 && year % 400 != 0)
	{
		return 365;
	}
	
	return 366;
}

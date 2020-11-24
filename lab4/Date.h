#ifndef DATE_H
#define DATE_H
#include <iostream>

class Date
{
public:
    Date(int dd, int mm, int yy);
    ~Date() = default;

    int GetDay() const;
    int GetMonth() const;
    int GetYear() const;

    friend std::ostream& operator<<(std::ostream& out, const Date& object);
private:
    int _day;
    int _month;
    int _year;
};

#endif // !DATE_H
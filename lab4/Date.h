#ifndef DATE_H
#define DATE_H
#include <iostream>

class Date
{
public:
    Date(int dd, int mm, int yy);
    Date();
    ~Date()                            = default;

    int GetDay()                       const;
    int GetMonth()                     const;
    int GetYear()                      const;

    int GetDaysCount() const;
	static int GetDaysCountInMonth(int month, int year);
	static int GetDaysCountInYear(int year);

    bool operator==(const Date& other) const;
    bool operator!=(const Date& other) const;
	bool operator<(const Date& other)  const;
    bool operator>(const Date& other)  const;

    friend std::ostream& operator<<(std::ostream& out, const Date& object);
private:
    int                                _day;
    int                                _month;
    int                                _year;
};

#endif // !DATE_H
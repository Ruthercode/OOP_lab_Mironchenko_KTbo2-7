#ifndef ELECTIONS_H
#define ELECTIONS_H
#include <string>
#include "Date.h"
class Elections 
{
public:
    Elections(const std::string& fullName, 
              const Date& dateOfBirth,
              const std::string& job, 
              const double& rating);
    ~Elections() = default;

    std::string GetFullName() const;
    Date GetDateOfBirth() const;
    std::string GetJob() const;
    double GetRating() const;

    friend std::ostream& operator<<(std::ostream& out, const Elections& object);
private:
    std::string _fullName;
    Date _dateOfBirth;
    std::string _job;
    double _rating;
};


#endif // !ELECTIONS_H
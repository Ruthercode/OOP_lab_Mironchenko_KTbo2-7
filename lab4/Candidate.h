#ifndef CANDIDATE_H
#define CANDIDATE_H
#include <string>
#include "Date.h"
class Candidate 
{
public:
    Candidate(const std::string& fullName, 
              const Date& dateOfBirth,
              const std::string& job, 
              const double& rating);
    ~Candidate() = default;

    std::string GetFullName() const;
    Date GetDateOfBirth() const;
    std::string GetJob() const;
    double GetRating() const;

    friend std::ostream& operator<<(std::ostream& out, const Candidate& object);
private:
    std::string _fullName;
    Date _dateOfBirth;
    std::string _job;
    double _rating;
};


#endif // !CANDIDATE_H
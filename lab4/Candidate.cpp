#include "Candidate.h"
#include <iostream>

Candidate::Candidate(const std::string& fullName, 
              const Date& dateOfBirth,
              const std::string& job, 
              const double& rating): _fullName(fullName),
                                     _dateOfBirth(dateOfBirth),
                                     _job(job),
                                     _rating(rating)                        
{
    if (_rating < 0.0)
        throw std::logic_error("bad rating\n");
}


std::string Candidate::GetFullName() const
{
    return _fullName;
}
Date Candidate::GetDateOfBirth() const
{
    return _dateOfBirth;
}
std::string Candidate::GetJob() const
{
    return _job;
}
double Candidate::GetRating() const
{
    return _rating;
}

std::ostream& operator<<(std::ostream& out, const Candidate& object)
{
    out << "-----------------------------\n";
    out << "Full name: " << object._fullName <<"\n";
    out << "Date of birth: " << object._dateOfBirth <<"\n";
    out << "Place of job: " << object._job <<"\n";
    out << "Raiting: " << object._rating <<"\n";
    out << "-----------------------------\n";
    return out;
}
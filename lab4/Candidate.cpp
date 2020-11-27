#include "Candidate.h"
#include <iostream>

int Candidate::s_idGenerator = 1;

Candidate::Candidate(const std::string& fullName, 
              const Date& dateOfBirth,
              const std::string& job, 
              const double& rating): _fullName(fullName),
                                     _dateOfBirth(dateOfBirth),
                                     _job(job),
                                     _rating(rating),
                                     _objectID(s_idGenerator++)                        
{
    if (_rating < 0.0)
        throw std::logic_error("bad rating\n");
}

int Candidate::GetID() const
{
    return _objectID;
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
    out << "---------------------------------------------------\n"
    << "Id: " << object._objectID <<"\n"
    << "Full name: " << object._fullName <<"\n"
    << "Date of birth: " << object._dateOfBirth <<"\n"
    << "Place of job: " << object._job <<"\n"
    << "Raiting: " << object._rating <<"\n";
    return out;
}
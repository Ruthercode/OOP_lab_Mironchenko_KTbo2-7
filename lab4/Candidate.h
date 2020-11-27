#ifndef CANDIDATE_H
#define CANDIDATE_H
#include <string>
#include "Date.h"
class Candidate 
{
friend class CandidateMap;
friend class CandidateVector;
public:
    Candidate(const std::string& fullName, const Date& dateOfBirth, const std::string& job, const double& rating);
    Candidate()               = default;
    ~Candidate()              = default;

    std::string GetFullName() const;
    Date GetDateOfBirth()     const;
    std::string GetJob()      const;
    double GetRating()        const;
    int GetID()               const;

    friend std::ostream& operator<<(std::ostream& out, const Candidate& object);
private:
    static int                s_idGenerator;
    int                       _objectID;
    std::string               _fullName;
    Date                      _dateOfBirth;
    std::string               _job;
    double                   _rating;
};


#endif // !CANDIDATE_H
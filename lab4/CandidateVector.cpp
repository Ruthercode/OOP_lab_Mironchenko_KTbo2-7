#include "CandidateVector.h"

void CandidateVector::AddItem(const Candidate& item) 
{
    _vec.push_back(item);
}

std::vector<Candidate> CandidateVector::Search(double rait) const 
{
    if (rait < 0.0 || rait > 100.0)
        throw std::logic_error("bad rating\n");
    
    std::vector<Candidate> candidates;

    for (int i =0; i < _vec.size(); ++i)
    {
        if (_vec[i].GetRating() > rait)
        {
            candidates.push_back(_vec[i]);
        }
    }

    return candidates;
}
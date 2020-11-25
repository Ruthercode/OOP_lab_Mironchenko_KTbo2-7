#include "CandidateMap.h"

void CandidateMap::AddItem(const Candidate& item)
{
    _map.insert(std::pair<double, Candidate>(item.GetRating(),item));
}

std::vector<Candidate> CandidateMap::Search(double rait) const
{

    if (rait < 0.0 || rait > 100.0)
        throw std::logic_error("bad rating\n");
    
    std::vector<Candidate> candidates;

    for (auto it = _map.begin(); it != _map.end(); ++it)
    {
        if (it->first > rait)
        {
            candidates.push_back(it->second);
        }
    }

    return candidates;
}

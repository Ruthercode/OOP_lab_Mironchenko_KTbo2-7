#ifndef CANDIDATE_MAP_H
#define CANDIDATE_MAP_H

#include <vector>
#include <map>

#include "Candidate.h"
#include "ICandidateContainer.h"

class CandidateMap : public ICandidateContainer
{
public:
    CandidateMap() = default;
    ~CandidateMap() override = default;

    void AddItem(const Candidate& item) override;
	std::vector<Candidate> Search(double rait) const override;
    
private:
    std::multimap<double, Candidate> _map;
};

#endif // !CANDIDATE_MAP_H

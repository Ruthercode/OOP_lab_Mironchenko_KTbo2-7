#ifndef CANDIDATE_VECTOR_H
#define CANDIDATE_VECTOR_H

#include <vector>

#include "Candidate.h"
#include "ICandidateContainer.h"

class CandidateVector : public ICandidateContainer
{
public:
    
    void AddItem(const Candidate& item) override;
	std::vector<Candidate> Search(double rait) const override;

    ~CandidateVector() override = default;
private:
    std::vector<Candidate> _vec;
};

#endif // !CANDIDATE_VECTOR_H

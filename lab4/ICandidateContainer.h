#ifndef I_CANDIDATE_CONTAINER_H
#define I_CANDIDATE_CONTAINER_H
#include "Candidate.h"
#include <vector>
class ICandidateContainer 
{
public:
	ICandidateContainer() = default;

	virtual void AddItem(const Candidate& item) = 0;
	virtual std::vector<Candidate> Search(double rait) const = 0;
	virtual ~ICandidateContainer() {};

};


#endif // !I_CANDIDATE_CONTAINER_H

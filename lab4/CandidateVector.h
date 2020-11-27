#ifndef CANDIDATE_VECTOR_H
#define CANDIDATE_VECTOR_H

#include <vector>

#include "Candidate.h"
#include "ICandidateContainer.h"

class CandidateVector : public ICandidateContainer
{
public:
    CandidateVector()                                                 =default;
    ~CandidateVector() override                                       =default;

    void AddItem(const Candidate& item)                               override;
	std::vector<Candidate*> SearchByRating(double rait, char mode)    override;
	std::vector<Candidate*> SearchByName(const std::string& name)     override;
	std::vector<Candidate*> SearchByJobPlace(const std::string& job)  override;
	std::vector<Candidate*> SearchByBirthDate(Date date, char mode)   override;
	std::vector<Candidate*> GetCandidates()                           override;

	void UpdateRatingById(int id, double rating)                      override;
	void UpdateNameById(int id, const std::string& name)              override;
	void UpdateJobPlaceById(int id, const std::string& job)           override;
	void UpdateBirthDatById(int id, Date date)                        override;
	
	void RemoveById(int id)                                           override;
	Candidate* FindById(int id)                                       override;
private:
    std::vector<Candidate>                                            _candidates;
};

#endif // !CANDIDATE_VECTOR_H

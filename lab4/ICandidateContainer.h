#ifndef I_CANDIDATE_CONTAINER_H
#define I_CANDIDATE_CONTAINER_H
#include "Candidate.h"
#include <vector>

class ICandidateContainer 
{
public:
	ICandidateContainer()                                                     =default;
	virtual ~ICandidateContainer() {};

	virtual void AddItem(const Candidate& item)                               =0;

	virtual std::vector<Candidate*> SearchByRating(double rait, char mode)    =0;
	virtual std::vector<Candidate*> SearchByName(const std::string& name)     =0;
	virtual std::vector<Candidate*> SearchByJobPlace(const std::string& job)  =0;
	virtual std::vector<Candidate*> SearchByBirthDate(Date date, char mode)   =0;
	
	virtual std::vector<Candidate*> GetCandidates()                           =0;

	virtual void UpdateRatingById(int id, double rating)                      =0;
	virtual void UpdateNameById(int id, const std::string& name)              =0;
	virtual void UpdateJobPlaceById(int id, const std::string& job)           =0;
	virtual void UpdateBirthDatById(int id, Date date)                        =0;

	virtual void RemoveById(int id)                                           =0;

	virtual Candidate* FindById(int id)                                       =0;
};


#endif // !I_CANDIDATE_CONTAINER_H

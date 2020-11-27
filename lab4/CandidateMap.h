#ifndef CANDIDATE_MAP_H
#define CANDIDATE_MAP_H

#include <map>
#include <set>
#include "Candidate.h"
#include "ICandidateContainer.h"

class CandidateMap : public ICandidateContainer
{
public:
    CandidateMap()                                                    =default;
    ~CandidateMap() override                                          =default;

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
    std::map< int, Candidate >                                        _candidates;

	std::map< double, std::set<int> >                                 _candidatesByRating;
	std::map< std::string, std::set<int> >                            _candidatesByName;
	std::map< std::string, std::set<int> >                            _candidatesByJob;
	std::map< Date, std::set<int> >                                   _candidatesByBirthDate;
};

#endif // !CANDIDATE_MAP_H

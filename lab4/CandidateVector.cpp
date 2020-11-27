#include "CandidateVector.h"
#include <math.h>

void CandidateVector::AddItem(const Candidate& item) 
{
    _candidates.push_back(item);
}

void CandidateVector::RemoveById(int id)    
{
    for (int i = 0; i < _candidates.size(); ++i)
    {
        if (_candidates[i].GetID() == id)
        {
            _candidates.erase(_candidates.begin() + i);
            break;
        }
    }
}

Candidate* CandidateVector::FindById(int id)                                       
{
    for (Candidate& c : _candidates)
    {
        if (c.GetID() == id) return &c;
    }
    return nullptr;
}

void CandidateVector::UpdateRatingById(int id, double rating) 
{
    Candidate* toUpdate = FindById(id);

    if (toUpdate != nullptr) toUpdate->_rating = rating;
}
void CandidateVector::UpdateNameById(int id, const std::string& name)
{
    Candidate* toUpdate = FindById(id);

    if (toUpdate != nullptr) toUpdate->_fullName = name;
}
void CandidateVector::UpdateJobPlaceById(int id, const std::string& job) 
{
    Candidate* toUpdate = FindById(id);

    if (toUpdate != nullptr) toUpdate->_job = job;
}
void CandidateVector::UpdateBirthDatById(int id, Date date) 
{
    Candidate* toUpdate = FindById(id);

    if (toUpdate != nullptr) toUpdate->_dateOfBirth = date;
}

std::vector<Candidate*> CandidateVector::SearchByRating(double rait, char mode)    
{
    if (mode != 'E' && mode != 'L' && mode != 'M')
    {
        throw std::invalid_argument("Bad comporation type");
    }

    std::vector<Candidate*> toReturn;

    for (int i = 0; i < _candidates.size(); ++i)
    {
        if (mode == 'E' && (abs(_candidates[i].GetRating() - rait) < 1e6))
        {
            toReturn.push_back(&_candidates[i]);
        }
        else if (mode == 'L' && _candidates[i].GetRating() < rait)
        {
            toReturn.push_back(&_candidates[i]);
        }
        else if (mode == 'M' && _candidates[i].GetRating() > rait)
        {
            toReturn.push_back(&_candidates[i]);
        }
    }  
    return toReturn;
}

std::vector<Candidate*> CandidateVector::SearchByName(const std::string& name)     
{
    std::vector<Candidate*> toReturn;

    for (int i = 0; i < _candidates.size(); ++i)
    {
        if (_candidates[i].GetFullName() == name)
        {
            toReturn.push_back(&_candidates[i]);
        }
    }  
    return toReturn;
}
std::vector<Candidate*> CandidateVector::SearchByJobPlace(const std::string& job) 
{
    std::vector<Candidate*> toReturn;

    for (int i = 0; i < _candidates.size(); ++i)
    {
        if (_candidates[i].GetFullName() == job)
        {
            toReturn.push_back(&_candidates[i]);
        }
    }  
    return toReturn;
}
std::vector<Candidate*> CandidateVector::SearchByBirthDate(Date date, char mode)   
{
    if (mode != 'E' && mode != 'L' && mode != 'M')
    {
        throw std::invalid_argument("Bad comporation type");
    }

    std::vector<Candidate*> toReturn;

    for (int i = 0; i < _candidates.size(); ++i)
    {
        if (mode == 'E' && date == _candidates[i].GetDateOfBirth())
        {
            toReturn.push_back(&_candidates[i]);
        }
        else if (mode == 'L' && _candidates[i].GetDateOfBirth() < date)
        {
            toReturn.push_back(&_candidates[i]);
        }
        else if (mode == 'M' && _candidates[i].GetDateOfBirth() > date)
        {
            toReturn.push_back(&_candidates[i]);
        }
    }  
    return toReturn;
}

std::vector<Candidate*> CandidateVector::GetCandidates()
{
    std::vector<Candidate*> toReturn(_candidates.size());
    for (int i = 0; i < _candidates.size(); ++i)
    {
        toReturn[i] = &_candidates[i];
    }
    return toReturn;
}


#include "CandidateMap.h"

void CandidateMap::AddItem(const Candidate& item)
{
    int id = item.GetID();
    _candidates.insert(std::pair<int, Candidate>(id,item));

    auto itRating = _candidatesByRating.find(item.GetRating());
    auto itName = _candidatesByName.find(item.GetFullName());
    auto itJob = _candidatesByJob.find(item.GetJob());
    auto itDate = _candidatesByBirthDate.find(item.GetDateOfBirth());

    if (itRating != _candidatesByRating.end())
    {
        itRating->second.insert(id);
    }
    else
    {
        _candidatesByRating[item.GetRating()] = std::set<int>();
        _candidatesByRating[item.GetRating()].insert(id);
    }

    if (itName != _candidatesByName.end())
    {
        itName->second.insert(id);
    }
    else
    {
        _candidatesByName[item.GetFullName()] = std::set<int>();
        _candidatesByName[item.GetFullName()].insert(id);
    }
    
    if (itJob != _candidatesByJob.end())
    {
        itJob->second.insert(id);
    }
    else
    {
        _candidatesByJob[item.GetJob()] = std::set<int>();
        _candidatesByJob[item.GetJob()].insert(id);
    }

    if (itDate != _candidatesByBirthDate.end())
    {
        itDate->second.insert(id);
    }
    else
    {
        _candidatesByBirthDate[item.GetDateOfBirth()] = std::set<int>();
        _candidatesByBirthDate[item.GetDateOfBirth()].insert(id);
    }
}

void CandidateMap::RemoveById(int id)  
{
    auto it = _candidates.find(id);
    if (it != _candidates.end())
    {
        _candidatesByRating[it->second.GetRating()].erase(id);
        _candidatesByName[it->second.GetFullName()].erase(id);
        _candidatesByJob[it->second.GetJob()].erase(id);
        _candidatesByBirthDate[it->second.GetDateOfBirth()].erase(id);

        _candidates.erase(id);
    }
}

Candidate* CandidateMap::FindById(int id)
{
    auto it = _candidates.find(id);

    if (it != _candidates.end()) return &(it->second);

    return nullptr;
}

void CandidateMap::UpdateRatingById(int id, double rating) 
{
    Candidate* toUpdate = FindById(id);

    if (toUpdate != nullptr) 
    {
        _candidatesByRating[toUpdate->_rating].erase(id);
        _candidatesByRating[rating].insert(id);

        toUpdate->_rating = rating;
    }
}
void CandidateMap::UpdateNameById(int id, const std::string& name)
{
    Candidate* toUpdate = FindById(id);

    if (toUpdate != nullptr) 
    {
        _candidatesByName[toUpdate->_fullName].erase(id);
        _candidatesByName[name].insert(id);

        toUpdate->_fullName = name;
    }
}
void CandidateMap::UpdateJobPlaceById(int id, const std::string& job) 
{
    Candidate* toUpdate = FindById(id);

    if (toUpdate != nullptr) 
    {
        _candidatesByJob[toUpdate->_job].erase(id);
        _candidatesByJob[job].insert(id);

        toUpdate->_job = job;
    }
}
void CandidateMap::UpdateBirthDatById(int id, Date date) 
{
    Candidate* toUpdate = FindById(id);

    if (toUpdate != nullptr) 
    {
        _candidatesByBirthDate[toUpdate->_dateOfBirth].erase(id);
        _candidatesByBirthDate[date].insert(id);

        toUpdate->_dateOfBirth = date;
    }
}

std::vector<Candidate*> CandidateMap::SearchByRating(double rait, char mode)
{
    if (mode != 'E' && mode != 'L' && mode != 'M')
    {
        throw std::invalid_argument("Bad comporation type");
    }

    std::vector<Candidate*> toReturn;

    if (mode == 'E')
    {
        auto it = _candidatesByRating.find(rait);
        if (it != _candidatesByRating.end())
        {
            auto itSet = it->second.begin();
            for (;itSet != it->second.end();++itSet)
            {
                toReturn.push_back(&_candidates[*itSet]);
            }
        }
    }
    else if (mode == 'L')
    {
        auto to = _candidatesByRating.lower_bound(rait);
        to++;

        for (auto it = _candidatesByRating.begin(); it != to; ++it)
        {
            if (it ==  _candidatesByRating.end() || it->first == rait) continue;
            else
            {
                auto itSet = it->second.begin();
                for (;itSet != it->second.end();++itSet)
                {
                    toReturn.push_back(&_candidates[*itSet]);
                }
            }
            
        }
    }
    else if (mode == 'M')
    {
        auto from = _candidatesByRating.upper_bound(rait);

        for (; from !=  _candidatesByRating.end(); ++from)
        {
            auto itSet = from->second.begin();
            for (;itSet != from->second.end();++itSet)
            {
                toReturn.push_back(&_candidates[*itSet]);
            }
        }
    }
    return toReturn;
}

std::vector<Candidate*> CandidateMap::SearchByName(const std::string& name)
{
    std::vector<Candidate*> toReturn;

    auto it = _candidatesByName.find(name);
    if (it != _candidatesByName.end())
    {
        auto itSet = it->second.begin();
        for (;itSet != it->second.end();++itSet)
        {
            toReturn.push_back(&_candidates[*itSet]);
        }
    }

    return toReturn;
}
std::vector<Candidate*> CandidateMap::SearchByJobPlace(const std::string& job) 
{
    std::vector<Candidate*> toReturn;

    auto it = _candidatesByJob.find(job);
    if (it != _candidatesByJob.end())
    {
        auto itSet = it->second.begin();
        for (;itSet != it->second.end();++itSet)
        {
            toReturn.push_back(&_candidates[*itSet]);
        }
    }

    return toReturn;
}
std::vector<Candidate*> CandidateMap::SearchByBirthDate(Date date, char mode)
{
    if (mode != 'E' && mode != 'L' && mode != 'M')
    {
        throw std::invalid_argument("Bad comporation type");
    }

    std::vector<Candidate*> toReturn;

    if (mode == 'E')
    {
        auto it = _candidatesByBirthDate.find(date);
        if (it != _candidatesByBirthDate.end())
        {
            auto itSet = it->second.begin();
            for (;itSet != it->second.end();++itSet)
            {
                toReturn.push_back(&_candidates[*itSet]);
            }
        }
    }
    else if (mode == 'L')
    {
        auto to = _candidatesByBirthDate.lower_bound(date);
        to++;

        for (auto it = _candidatesByBirthDate.begin(); it != to; ++it)
        {
            if (it ==  _candidatesByBirthDate.end() || it->first == date) continue;
            else
            {
                auto itSet = it->second.begin();
                for (;itSet != it->second.end();++itSet)
                {
                    toReturn.push_back(&_candidates[*itSet]);
                }
            }
            
        }
    }
    else if (mode == 'M')
    {
        auto from = _candidatesByBirthDate.upper_bound(date);

        for (; from !=  _candidatesByBirthDate.end(); ++from)
        {
            auto itSet = from->second.begin();
            for (;itSet != from->second.end();++itSet)
            {
                toReturn.push_back(&_candidates[*itSet]);
            }
        }
    }

    return toReturn;
}

std::vector<Candidate*> CandidateMap::GetCandidates()
{
    std::vector<Candidate*> toReturn;
    for (auto it = _candidates.begin(); it != _candidates.end(); ++it)
    {
        toReturn.push_back(&it->second);
    }
    return toReturn;
}
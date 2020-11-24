#include "ElectionsVector.h"

void ElectionsVector::AddItem(const Elections& item) 
{
    _vec.push_back(item);
}

std::vector<Elections> ElectionsVector::Search(double rait) const 
{
    if (rait < 0.0)
        throw std::logic_error("bad rating\n");
    
    std::vector<Elections> candidates;

    for (int i =0; i < _vec.size(); ++i)
    {
        if (_vec[i].GetRating() > rait)
        {
            candidates.push_back(_vec[i]);
        }
    }

    return candidates;
}
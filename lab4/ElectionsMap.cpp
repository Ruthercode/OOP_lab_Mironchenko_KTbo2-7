#include "ElectionsMap.h"

void ElectionsMap::AddItem(const Elections& item)
{
    _map.insert(std::pair<double, Elections>(item.GetRating(),item));
}

std::vector<Elections> ElectionsMap::Search(double rait) const
{

    if (rait < 0.0)
        throw std::logic_error("bad rating\n");
    
    std::vector<Elections> candidates;

    for (auto it = _map.begin(); it != _map.end(); ++it)
    {
        if (it->first > rait)
        {
            candidates.push_back(it->second);
        }
    }

    return candidates;
}

#ifndef ELECTIONS_MAP_H
#define ELECTIONS_MAP_H

#include <vector>
#include <map>

#include "Elections.h"
#include "IElectionsContainer.h"

class ElectionsMap : public IElectionsContainer
{
public:
    ElectionsMap() = default;
    ~ElectionsMap() override = default;

    void AddItem(const Elections& item) override;
	std::vector<Elections> Search(double rait) const override;
    
private:
    std::multimap<double, Elections> _map;
};

#endif // !ELECTIONS_MAP_H

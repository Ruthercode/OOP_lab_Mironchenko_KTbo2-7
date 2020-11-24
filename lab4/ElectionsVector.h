#ifndef ELECTIONS_VECTOR_H
#define ELECTIONS_VECTOR_H

#include <vector>

#include "Elections.h"
#include "IElectionsContainer.h"

class ElectionsVector : public IElectionsContainer
{
public:
    
    void AddItem(const Elections& item) override;
	std::vector<Elections> Search(double rait) const override;

    ~ElectionsVector() override = default;
private:
    std::vector<Elections> _vec;
};

#endif // !ELECTIONS_VECTOR_H

#ifndef I_ELECTIONS_CONTAINER_H
#define I_ELECTIONS_CONTAINER_H
#include "Elections.h"
#include <vector>
class IElectionsContainer 
{
public:
	IElectionsContainer() = default;

	virtual void AddItem(const Elections& item) = 0;
	virtual std::vector<Elections> Search(double rait) const = 0;
	virtual ~IElectionsContainer() {};

};


#endif // !I_ELECTIONS_CONTAINER_H

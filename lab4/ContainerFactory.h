#ifndef CONTAINER_FACTORY_H
#define CONTAINER_FACTORY_H

#include "IElectionsContainer.h"
#include "ElectionsMap.h"
#include "ElectionsVector.h"

class ContainerFactory
{
public:
    ContainerFactory() = default;
    ~ContainerFactory() = default;
    IElectionsContainer* GetContainer(char type);
};


#endif // !CONTAINER_FACTORY_H

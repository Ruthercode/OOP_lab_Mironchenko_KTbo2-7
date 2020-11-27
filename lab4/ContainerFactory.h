#ifndef CONTAINER_FACTORY_H
#define CONTAINER_FACTORY_H

#include "ICandidateContainer.h"
#include "CandidateMap.h"
#include "CandidateVector.h"

class ContainerFactory
{
public:
    ContainerFactory()  = default;
    ~ContainerFactory() = default;
    ICandidateContainer* GetContainer(char type);
};


#endif // !CONTAINER_FACTORY_H

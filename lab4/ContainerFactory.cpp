#include "ContainerFactory.h"

ICandidateContainer* ContainerFactory::GetContainer(char type)
{
    if (type == 'v')
    {
        return new CandidateVector;
    }
    else if (type == 'm')
    {
        return new CandidateMap;
    }
    else
    {
        return nullptr;
    }
    
}
#include "ContainerFactory.h"

ICandidateContainer* ContainerFactory::GetContainer(char type)
{
    if (type == 'V')
    {
        return new CandidateVector;
    }
    else if (type == 'M')
    {
        return new CandidateMap;
    }
    else
    {
        return nullptr;
    }
    
}
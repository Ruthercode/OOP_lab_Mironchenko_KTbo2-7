#include "ContainerFactory.h"

IElectionsContainer* ContainerFactory::GetContainer(char type)
{
    if (type == 'v')
    {
        return new ElectionsVector;
    }
    else if (type == 'm')
    {
        return new ElectionsMap;
    }
    else
    {
        return nullptr;
    }
    
}
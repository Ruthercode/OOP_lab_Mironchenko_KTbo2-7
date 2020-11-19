#ifndef FABRIC_H
#define FABRIC_H

#include "container.h" 

#include "customer.h" 
#include "food.h" 

class ContainerFactory
{
    public:
    ContainerFactory() {};
    ~ContainerFactory() {};

    Container<Customer>* getClientsList(bool isStack);
    Container<Food>* getFoodList(bool isStack);
};

#endif /* FABRIC_H */
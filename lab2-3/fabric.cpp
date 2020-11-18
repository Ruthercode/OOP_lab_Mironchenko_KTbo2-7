#include "container.h" 

#include "customer.h" 
#include "food.h" 

#include "queue.h" 
#include "stack.h" 
#include "fabric.h"

Container<Customer>* ContainerFabric::getClientsList(bool isStack)
{
    if (isStack) return new Stack<Customer>;
    else return new Queue<Customer>;
}

Container<Food>* ContainerFabric::getFoodList(bool isStack)
{
    if (isStack) return new Stack<Food>;
    else return new Queue<Food>;
}
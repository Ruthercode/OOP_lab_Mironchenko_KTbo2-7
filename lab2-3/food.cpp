#include <string>
#include "food.h"
#include <iostream>

Food::Food(std::string name, unsigned int cost): _name(name), _cost(cost) {}
Food::~Food() {}

std::string Food::getNameOfFood() const 
{
    return _name;
}

unsigned int Food::getCostOfFood() const 
{
    return _cost;
}

std::ostream& operator<<(std::ostream& out, const Food& object)
{
    out << "The \"" << object._name << "\" dish costs " << object._cost << "$\n";
    return out;
}
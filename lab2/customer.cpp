#include <string>
#include "food.h"
#include "customer.h"
#include <iostream>

Customer::Customer(std::string name, unsigned int money): _name(name), _money(money) {}
Customer::~Customer() {}

std::string Customer::getNameOfClient() const 
{
    return _name;
}

unsigned int Customer::getClientMoney() const 
{
    return _money;
}

bool Customer::buyFood(const Food& food)
{
    unsigned int cost = food.getCostOfFood();
    if (_money >= cost)
    {
        _money -= cost;
        return true;
    }
    else
    {
        return false;
    }
}

std::ostream& operator<<(std::ostream& out, const Customer& object)
{
    out << "Customer " << object._name << " has " << object._money << "$\n";
    return out;
}
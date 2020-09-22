#ifndef CLIENT_H
#define CLIENT_H
#include <string>
#include "food.h"

class Customer 
{
    private:
        std::string _name;
        unsigned int _money;
    public:
        Customer(std::string name, unsigned int money);
        ~Customer();

        std::string getNameOfClient() const;

        unsigned int getClientMoney() const;

        bool buyFood(const Food& food);

        friend std::ostream& operator<<(std::ostream& out, const Customer& object);
};

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
#endif // CLIENT_H
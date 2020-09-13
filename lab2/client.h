#ifndef CLIENT_H
#define CLIENT_H
#include <string>
#include "food.h"

class Client 
{
    private:
        std::string _name;
        unsigned int _money;
    public:
        Client(std::string name, unsigned int money): _name(name), _money(money) {}
        ~Client() {}

        std::string getNameOfClient() const 
        {
            return _name;
        }

        unsigned int getClientMoney() const 
        {
            return _money;
        }

        bool buyFood(const Food& food)
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

        friend std::ostream& operator<<(std::ostream& out, const Client& object)
        {
            out << "Client " << object._name << " has " << object._money << "$\n";
            return out;
        }
};

#endif // CLIENT_H
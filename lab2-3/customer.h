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


#endif // CLIENT_H
#ifndef FOOD_H
#define FOOD_H
#include <string>

class Food
{
    private:
        std::string _name;
        unsigned int _cost;
    public:

        Food(std::string name, unsigned int cost): _name(name), _cost(cost) {}
        ~Food() {}

        std::string getNameOfFood() const 
        {
            return _name;
        }

        unsigned int getCostOfFood() const 
        {
            return _cost;
        }

        friend std::ostream& operator<<(std::ostream& out, const Food& object)
        {
            out << "The \"" << object._name << "\" dish costs " << object._cost << "$\n";
            return out;
        }
};
#endif // FOOD_H
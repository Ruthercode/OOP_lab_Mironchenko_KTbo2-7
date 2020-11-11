#ifndef FOOD_H
#define FOOD_H
#include <string>

class Food
{
    private:
        std::string _name;
        unsigned int _cost;
    public:

        Food(std::string name, unsigned int cost);
        ~Food();

        std::string getNameOfFood() const;

        unsigned int getCostOfFood() const;

        friend std::ostream& operator<<(std::ostream& out, const Food& object);
};

#endif // FOOD_H
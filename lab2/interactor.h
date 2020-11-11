#ifndef INTERACTOR_H
#define INTERACTOR_H
#include <iostream>
#include <fstream>

#include "queue.h"
#include "stack.h"
#include "food.h"
#include "customer.h"
class Interactor
{
    private:
        Queue<Customer> _clients;
        Stack<Food> _food;

        void _help() const;
    public:
        Interactor();
        ~Interactor();
        void init(const std::string& clients_list, const std::string& food_list);
};

#endif 
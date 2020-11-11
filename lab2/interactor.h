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
        Container<Customer>* _clients;
        Container<Food>* _food;

        void _help() const;
        void _fileInput(const std::string& clients_list, const std::string& food_list);
        void _interaction();
    public:
        Interactor();
        ~Interactor();
        void init(const std::string& clients_list, const std::string& food_list);
};

#endif 
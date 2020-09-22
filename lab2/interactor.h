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


void Interactor::_help() const
{
    std::cout <<"===========================================\n";
    std::cout << "Disclaimer: \nYou have a restaurant.\n";
    std::cout << "He displays his dishes on the window.\n";
    std::cout << "There is a line of customers to him.\n";
    std::cout <<"Each client wants to buy the freshest dish.\n";
    std::cout <<"===========================================\n";
    std::cout << "Commands: \n";
    std::cout << "1) Show clients\n";
    std::cout << "2) Show dishes\n";
    std::cout << "3) Customer buy a dish\n";
    std::cout << "4) Add new dish\n";
    std::cout << "5) Add new client\n";
    std::cout << "6) Help\n";
    std::cout << "0) Exit\n";
    std::cout <<"===========================================\n";
}

Interactor::Interactor(): _clients(Queue<Customer>()), _food(Stack<Food>()) {}
Interactor::~Interactor() {}

void Interactor::init(const std::string& clients_list, const std::string& food_list)
{
    std::ifstream fin(clients_list);

    int num_of_clients;
    fin >> num_of_clients;

    for (int i = 0; i < num_of_clients; ++i)
    {
        std::string name;
        int money;
        fin >> name >> money;
        _clients.push( Customer(name,money) );
    }
    fin.close();

    std::ifstream in(food_list);

    int num_of_food;
    in >> num_of_food;

    for (int i = 0; i < num_of_food; ++i)
    {
        std::string name;
        int cost;
        in >> name >> cost;
        _food.push(Food(name, cost));
    }
    in.close();

    _help();

    int command = 1;
    while (command)
    {
        std::cout << "#Command: ";
        std::cin >> command;

        std::string name;
        unsigned int x;
        switch (command)
        {
        case 1:
            std::cout << _clients;
            break;
        
        case 2:
            std::cout << _food;
            break;
        
        case 3:
            if (_clients.isEmpty())
            {
                std::cout << "There are no customers in the queue.\n";
            }
            else if (_food.isEmpty())
            {
                std::cout << "There are no dishes in the stack.\n";
            }
            else if (_clients.front().buyFood(_food.front()))
            {
                std::cout << _clients.front().getNameOfClient() 
                        << " bought " << _food.front().getNameOfFood()
                        << " for $ " << _food.front().getCostOfFood() << '\n';

                _clients.pop();
                _food.pop();
            }
            else
            {
                std::cout << "The client does not have enough money for food.\n";
                _clients.pop();
            }
            break;
        
        case 4:
            
            std::cout << "Enter the name of the dish and its cost: ";
            std::cin >> name >> x;
            _food.push(Food(name, x));
            break;
        
        case 5:
            std::cout << "Enter the name of the client and the amount of his money: ";
            std::cin >> name >> x;
            _clients.push(Customer(name, x));
            break;

        case 6:
            _help();
            break;
        
        default:
            break;
        }
    }
}
#endif 
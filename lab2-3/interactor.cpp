#include <iostream>
#include <fstream>

#include "queue.h"
#include "stack.h"
#include "food.h"
#include "customer.h"
#include "interactor.h"
#include "factory.h"

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

Interactor::Interactor(): _clients(nullptr), _food(nullptr), _factory(ContainerFactory()) {}
Interactor::~Interactor() 
{
    delete _clients;
    delete _food;
}

void Interactor::_fileInput(const std::string& clients_list, const std::string& food_list)
{
    std::ifstream fin(clients_list);

    int num_of_clients;
    fin >> num_of_clients;

    for (int i = 0; i < num_of_clients; ++i)
    {
        std::string name;
        int money;
        fin >> name >> money;
        _clients->push( Customer(name,money) );
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
        _food->push(Food(name, cost));
    }
    in.close();
}

void Interactor::_interaction()
{
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
            std::cout << _clients->out();
            break;
        
        case 2:
            std::cout << _food->out();
            break;
        
        case 3:
            if (_clients->isEmpty())
            {
                std::cout << "There are no customers in the queue.\n";
            }
            else if (_food->isEmpty())
            {
                std::cout << "There are no dishes in the stack.\n";
            }
            else if (_clients->front().buyFood(_food->front()))
            {
                std::cout << _clients->front().getNameOfClient() 
                        << " bought " << _food->front().getNameOfFood()
                        << " for $ " << _food->front().getCostOfFood() << '\n';

                _clients->pop();
                _food->pop();
            }
            else
            {
                std::cout << "The client does not have enough money for food.\n";
                _clients->pop();
            }
            break;
        
        case 4:
            
            std::cout << "Enter the name of the dish and its cost: ";
            std::cin >> name >> x;
            _food->push(Food(name, x));
            break;
        
        case 5:
            std::cout << "Enter the name of the client and the amount of his money: ";
            std::cin >> name >> x;
            _clients->push(Customer(name, x));
            break;

        case 6:
            _help();
            break;
        
        default:
            break;
        }
    }
}
void Interactor::init(const std::string& clients_list, const std::string& food_list)
{
    std::cout << "Customers list are stack?(y/n)\n";
    char ans;
    std::cin >> ans;
    ans = tolower(ans);

    _clients = _factory.getClientsList(ans == 'y');
    
    
    std::cout << "Food list are stack?(y/n)\n";
    std::cin >> ans;
    ans = tolower(ans);

    _food = _factory.getFoodList(ans == 'y');

    _fileInput(clients_list, food_list);
    _help();
    _interaction();
}
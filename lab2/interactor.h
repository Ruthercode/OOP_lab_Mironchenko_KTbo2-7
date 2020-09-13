#ifndef INTERACTOR_H
#define INTERACTOR_H
#include <iostream>
#include <fstream>

#include "queue.h"
#include "stack.h"
#include "food.h"
#include "client.h"
class Interactor
{
    private:
        Queue<Client> _clients;
        Stack<Food> _food;
    public:
        Interactor(): _clients(Queue<Client>()), _food(Stack<Food>()) {}
        ~Interactor() {}
        void init(const std::string& clients_list, const std::string& food_list)
        {
            std::ifstream fin(clients_list);

            int num_of_clients;
            fin >> num_of_clients;

            for (int i = 0; i < num_of_clients; ++i)
            {
                std::string name;
                int money;
                fin >> name >> money;
                _clients.push( Client(name,money) );
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
        }
        
        void check()
        {
            std::cout << _clients;
            std::cout << _food;
        }
};

#endif 
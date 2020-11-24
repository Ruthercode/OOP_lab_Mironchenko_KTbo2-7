#ifndef INTERACTOR_H
#define INTERACTOR_H

#include <iostream>
#include <fstream>
#include <vector>
#include "IElectionsContainer.h"
#include "ContainerFactory.h"

class Interactor
{
public:
    Interactor();
    ~Interactor();
    void Init(const std::string& file_to_input);
private:
    IElectionsContainer* _container;
    void _Help() const;
    void _FileParse(const std::string& file_to_input);
    void _Interaction(const std::string& file_to_input);
    void _ChooseContainer();
};
Interactor::Interactor(): _container(nullptr)
{
}

Interactor::~Interactor()
{
    if (_container != nullptr)
    {
        delete _container;
    }
}

void Interactor::_Help() const
{
    std::cout <<"===========================================\n";
    std::cout << "Commands: \n";
    std::cout << "1) Add new item\n";
    std::cout << "2) Search for objects with higher ratingt\n";
    std::cout << "3) Change container type\n";
    std::cout << "4) Help\n";
    std::cout << "0) Exit\n";
    std::cout <<"===========================================\n";
}

void Interactor::_Interaction(const std::string& file_to_input) 
{
    int command = -1;

    while (command != 0)
    {
        std::cout <<"Please, enter your command: ";
        std::cin >> command;

        switch (command)
        {
            case 1:
                try 
                {
                    std::cout << "Please, enter full name: ";
                    std::string firstName;
                    std::string secondName;
                    std::string lastName;
                    std::cin >> firstName >> secondName >> lastName;
                    std::string fullName = firstName + " " + secondName + " " + lastName;

                    int d, m, y;

                    std::cout << "Please, enter a date (dd.mm.yy): ";
                    std::cin >> d;
                    std::cin.get();
                    std::cin >> m;
                    std::cin.get();
                    std::cin >> y;
                    
                    Date date(d,m,y);

                    std::cout << "Please, enter a place of job: ";
                    std::string job;
                    std::cin >> job;

                    std::cout << "Please, enter a rating: ";
                    double rait;
                    std::cin >> rait;

                    
                    _container->AddItem(Elections(fullName, date, job,rait));
                }
                catch (std::logic_error e)
                {
                    std::cout << "There is so mistakes in data: " << e.what() << '\n';
                }
                break;
            case 2:
                try 
                {
                    std::cout << "Enter a rating: ";
                    double rait;
                    std::cin >> rait;
                    std::vector<Elections> tmp = _container->Search(rait);
                    if (tmp.size() == 0)
                        std::cout << "No elements\n";
                    else
                    {
                        for (auto e : tmp)
                        {
                            std::cout << e;
                        }
                    }

                }
                catch (std::logic_error e)
                {
                    std::cout << "There is so mistakes in arg: " << e.what() << '\n';
                }
                break;
            
            case 3:
                delete _container;
                _ChooseContainer();
                _FileParse(file_to_input);
                break;
            
            case 4:
                _Help();
                break;
            case 0:
                break;
        }
    }
    
}
void Interactor::_FileParse(const std::string& file_to_input)
{
    int n;
    std::ifstream fin("in.txt");
    fin >> n;

    for (int i = 0; i < n; ++i)
    {
        try {
            std::string firstName;
            std::string secondName;
            std::string lastName;
            fin >> firstName >> secondName >> lastName;
            std::string fullName = firstName + " " + secondName + " " + lastName;

            int d, m, y;

            fin >> d;
            fin.get();
            fin >> m;
            fin.get();
            fin >> y;
            
            Date date(d,m,y);

            std::string job;
            fin >> job;

            double rait;
            fin >> rait;

            
            _container->AddItem(Elections(fullName, date, job,rait));
        }
        catch (std::logic_error e)
        {
            std::cout << "There is so mistakes in file: " << e.what() << '\n';
            exit(1);
        }
    }

    fin.close();
}

void Interactor::_ChooseContainer()
{
    std::cout << "Choose to type of a container [V: Vector, M: Map]: ";
    char type;
    std::cin >> type;

    ContainerFactory factory;
    _container = factory.GetContainer(tolower(type));

    while (_container == nullptr)
    {
        std::cout << "The given type doesn't exist. Choose from V and M [V: Vector, M: Map]: ";
        std::cin >> type;

        _container = factory.GetContainer(tolower(type));
    }
    std::cout << "You choose " << (type == 'V' ? "vector\n" : "map\n");
}
void Interactor::Init(const std::string& file_to_input)
{
    _ChooseContainer();
    _FileParse(file_to_input);
    std::cout << "Files parsed from " << file_to_input << '\n';
    
    _Help();
    _Interaction(file_to_input);

}
#endif 
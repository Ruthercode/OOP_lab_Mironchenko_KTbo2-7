#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "interactor.h"

Interactor::Interactor(): _first(nullptr), _second(nullptr) {}

void Interactor::readObjects(const std::string& file)
{
    std::ifstream fin(file); 

    int x,y;
    fin >> x >> y;

    if (_first != nullptr) delete _first;
    _first = new Matrix(x,y);
    fin >> *_first;

    fin >> x >> y;
    if (_second != nullptr) delete _second;
    _second = new Matrix(x,y);
    fin >> *_second;

    fin.close();
}

std::string Interactor::iteration(const char& command, const int&  target)
{
    if (command != '+' && command != '*' && command != 'T')
    {
        return "Bad command";
    }
    
    if (target < 1 || target > 2)
    {
        return "Bad target";
    }
    
    
    if (target == 2)
    {
        std::swap(_first,_second);
    }

    std::stringstream result;

    try 
    {
        if (command == '+')
        {
            _first->matrixSum(*_second);
        }
        else if (command == '*')
        {
            _first->matrixMul(*_second);
        }  
        else if (command == 'T')
        {
            _first->matrixTransposition();
        }
    }
    catch (std::logic_error e)
    {
        result << e.what() << '\n';
        return result.str();
    }
    catch (std::length_error e)
    {
        result << e.what() << '\n';
        return result.str();
    }
    
    
    result << *_first;

    if (target == 2)
    {
        std::swap(_first,_second);
    }
    
    return result.str();
}

void Interactor::help()
{
    std::cout << "\"+\" command - get matrix sum" << std::endl;
    std::cout << "\"*\" command - get matrix mul" << std::endl;
    std::cout << "\"T\" command - get matrix transposition" << std::endl;
    std::cout << "\"H\" command - get help" << std::endl;
    std::cout << "\"E\" command - exit" << std::endl;
}

void Interactor::init(const std::string& matrices)
{
    readObjects(matrices);
    
    char command;
    int target;

    help();

    do
    {
        std::cout << "write command: ";
        std::cin >> command;
        
        if (toupper(command)  == 'H')
        {
            help();
        }
        else if (toupper(command) == 'E')
        {
            break;
        }
        else
        {
            std::cout << "write num of target matrix (first or second): ";
            std::cin >> target;

            std::cout << "----------------------------------------\n";
            std::cout << iteration(command, target) << std::endl;
            std::cout << "----------------------------------------\n";
        }
    } while (command != 'E');
    
    std::cout << *_first << std::endl;
    std::cout << *_second << std::endl;
}
Interactor::~Interactor()
{
    if (_first != nullptr) delete _first;
    if (_second!= nullptr) delete _second;
}
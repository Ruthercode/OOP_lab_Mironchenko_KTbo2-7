#include <fstream>
#include <ostream>
#include <string>
#include <sstream>
#include "interactor.h"

Interactor::Interactor(): _first(nullptr), _second(nullptr) {}

void Interactor::readObjects(std::string file)
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

std::string Interactor::interaction(char command, int target, int cnt)
{
    if (command != '+' && command != '*' && command != 'T' )
    {
        return "Bad command";
    }
    
    if (target < 1 && target > 2)
    {
        return "Bad target";
    }
    
    
    if (target == 2)
    {
        std::swap(_first,_second);
    }

    std::stringstream result;
    result << cnt << ")\n";

    if (command == '+')
    {
        try 
        {
            _first->matrixSum(*_second);
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
    }

    else if (command == '*')
    {
        try 
        {
            _first->matrixMul(*_second);
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
    }  
    else if (command == 'T')
    {
        _first->matrixTransposition();
    }
    
    result << *_first;

    if (target == 2)
    {
        std::swap(_first,_second);
    }
    
    return result.str();
}

std::ostream& operator<<(std::ostream& out, const Interactor& object)
{
    out << "///////////////////////////////////\n";
    if (object._first == nullptr) 
    {
        out << "First matrix has no elements\n";
    }
    else 
    {
        out << *object._first;
    }

    if (object._second == nullptr) 
    {
        out << "Second matrix has no elements\n";
    }
    else 
    {
        out << *object._second;
    }
    out << "///////////////////////////////////\n";
    return out;
}

Interactor::~Interactor()
{
    if (_first != nullptr) delete _first;
    if (_second!= nullptr) delete _second;
}
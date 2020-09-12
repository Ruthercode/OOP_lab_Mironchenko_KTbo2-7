#ifndef STACK_H 
#define STACK_H 
#include "container.h"
#include "list.h"


template <class T> class Stack : public Container<T>
{
private:
    List<T> _stack;
    int _size;

public:
    Stack() : _size(0), _stack(List<T>()) {}


    void push(const T& val)
    {
        _stack.addToTail(val);
        _size++;
    }

    void pop()
    {
        if (_size)
        {
            _stack.deleteFromTail();
            _size--;
        }
        else 
        {
            throw std::logic_error("Stack is already empty");
        }
    }

    bool isEmpty() const
    {
        return _size;
    }

    T front() const
    {
        return _stack.tail();
    }
    ~Stack() {}
};



#endif /* STACK_H  */
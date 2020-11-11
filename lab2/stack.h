#ifndef STACK_H 
#define STACK_H 
#include "container.h"
#include "list.h"

#include <string>
#include <sstream>

template <class T> class Stack : public Container<T>
{
private:
    List<T> _stack;
    int _size;

public:
    Stack();
    ~Stack();

    void push(const T& val);
    void pop();

    bool isEmpty() const;
    int size() const;
    T front() const;

    std::string out() const;

};

template <typename T>
Stack<T>::Stack() : _size(0), _stack(List<T>()) {}

template <typename T>
Stack<T>::~Stack() {}

template <typename T>
void Stack<T>::push(const T& val)
{
    _stack.addToTail(val);
    _size++;
}

template <typename T>
void Stack<T>::pop()
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

template <typename T>
bool Stack<T>::isEmpty() const
{
    return (_size == 0);
}

template <typename T>
T Stack<T>::front() const
{
    return _stack.tail();
}

template <typename T>
int Stack<T>::size() const
{
    return _size;
}

template <typename T>
std::string Stack<T>::out() const
{
    std::stringstream out;
    out << "----------------------------\n";
    out << "Stack has " << _size << " elements:\n";
    out << _stack << "\n";
    out << "----------------------------\n";
    return out.str();
}
#endif /* STACK_H  */
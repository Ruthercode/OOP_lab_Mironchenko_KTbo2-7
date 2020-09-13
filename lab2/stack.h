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
    Stack();
    ~Stack();

    void push(const T& val);
    void pop();

    bool isEmpty() const;
    int size() const;
    T front() const;
    
    friend std::ostream& operator<<(std::ostream& out, const Stack<T>& object)
    {
        out << "----------------------------\n";
        out << "Stack has " << object._size << " elements:\n";
        out << object._stack << "\n";
        out << "----------------------------\n";
        return out;
    }
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
#endif /* STACK_H  */
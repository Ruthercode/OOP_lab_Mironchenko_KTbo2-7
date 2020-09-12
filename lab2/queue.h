#ifndef QUEUE_H
#define QUEUE_H
#include "container.h"
#include "list.h"


template <class T> class Queue : public Container<T>
{
private:
    List<T> _que;
    int _size;

public:
    Queue() : _size(0), _que(List<T>()) {}


    void push(const T& val)
    {
        _que.addToTail(val);
        _size++;
    }

    void pop()
    {
        if (_size)
        {
            _que.deleteFromHead();
            _size--;
        }
        else 
        {
            throw std::logic_error("Queue is already empty");
        }
    }

    bool isEmpty() const
    {
        return _size;
    }

    T front() const
    {
        return _que.head();
    }
    ~Queue() {}
};



#endif /* QUEUE_H */
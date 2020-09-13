#ifndef QUEUE_H
#define QUEUE_H
#include "container.h"
#include "list.h"

template <class T> class Queue : public Container<T>
{
private:
    
    int _size;
    List<T> _que;
public:
    
    Queue();
    ~Queue();

    void push(const T& val);
    void pop();

    bool isEmpty() const;
    int size() const;
    T front() const;
    
    friend std::ostream& operator<<(std::ostream& out, const Queue<T>& object)
    {
        out << "----------------------------\n";
        out << "Queue has " << object._size << " elements:\n";
        out << object._que << "\n";
        out << "----------------------------\n";
        return out;
    }
};

template <typename T>
Queue<T>::Queue() : _size(0), _que(List<T>()) {}

template <typename T>
Queue<T>::~Queue() {}

template <typename T>
void Queue<T>::push(const T& val)
{
    _que.addToTail(val);
    _size++;
}

template <typename T>
void Queue<T>::pop()
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

template <typename T>
bool Queue<T>::isEmpty() const
{
    return (_size == 0);
}

template <typename T>
T Queue<T>::front() const
{
    return _que.head();
}

template <typename T>
int Queue<T>::size() const
{
    return _size;
}


#endif /* QUEUE_H */
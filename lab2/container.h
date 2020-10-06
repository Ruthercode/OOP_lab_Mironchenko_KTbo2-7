#ifndef CONTAINER_H
#define CONTAINER_H

template <class T> class Container
{
public:
    Container() {};
    ~Container() {};
    virtual void push(const T& val) = 0;
    virtual void pop() = 0 ;
    virtual bool isEmpty() const = 0;
    virtual T front() const = 0;
    virtual int size() const = 0;
};



#endif /* CONTAINER_H */
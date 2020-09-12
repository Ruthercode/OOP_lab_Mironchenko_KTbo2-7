#ifndef CONTAINER_H
#define CONTAINER_H

class Container
{
public:
    virtual void push(const int& val) = 0;
    virtual void pop()= 0 ;
    virtual bool isEmpty() const = 0;
    virtual int front() const = 0;
    virtual ~Container() {};
};



#endif /* CONTAINER_H */
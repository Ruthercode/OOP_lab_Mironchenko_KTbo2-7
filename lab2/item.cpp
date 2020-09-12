#include "item.h"

template <class T> 
Item<T>::Item(): next(this), prev(this) {}

template <class T> 
Item<T>::Item(T val)
{
    data = val;
    next = this;
    prev = this;
}

template <class T> 
Item<T>::~Item(){}


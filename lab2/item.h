#ifndef ITEM_H
#define ITEM_H
 
template <class T> class Item
{
public:
    T data;
    Item<T>* next;
    Item<T>* prev;

    Item();
    Item(T val);

    ~Item();
};



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


#endif /* ITEM_H */
#ifndef ITEM_H
#define ITEM_H
 
template <typename T> class Item
{
public:
    T data;
    Item<T>* next;
    Item<T>* prev;

    Item();
    Item(T val);

    ~Item();
};

template <typename T>
Item<T>::Item(): next(this), prev(this) {}

template <typename T>
Item<T>::Item(T val)
{
    data = val;
    next = this;
    prev = this;
}

template <typename T>
Item<T>::~Item(){}
#endif /* ITEM_H */
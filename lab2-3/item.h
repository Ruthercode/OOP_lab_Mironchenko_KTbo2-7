#ifndef ITEM_H
#define ITEM_H
 
template <class T>  class Item
{
public:
    T data;
    Item<T>* next;
    Item<T>* prev;

    Item();
    Item(const T&  val);

    ~Item();
};

template <typename T>
Item<T>::Item(): next(this), prev(this) {}

template <typename T>
Item<T>::Item(const T&  val): data(val), next(this), prev(this) {}

template <typename T>
Item<T>::~Item(){}
#endif /* ITEM_H */
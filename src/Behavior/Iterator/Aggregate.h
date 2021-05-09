#pragma once
template <class Item>
class Iterator;

template <class Item>
class Aggregate
{
public:
    virtual ~Aggregate() {}
    virtual Iterator<Item> *CreateIterator() = 0;
    virtual Item GetAt(int index) const = 0;
    virtual void append(const Item &item) = 0;
    virtual int length() const = 0;
};

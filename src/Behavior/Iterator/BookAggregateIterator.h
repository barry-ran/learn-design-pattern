#pragma once
#include "Iterator.h"
template <class Item>
class BookAggregate;
template <class Item>
class BookAggregateIterator : public Iterator<Item>
{
public:
    BookAggregateIterator(BookAggregate<Item> *bookAggregate) : m_bookAggregate(bookAggregate) {}
    virtual bool hasNext() override
    {
        return m_bookAggregate->length() > 0 && m_currentIndex < m_bookAggregate->length() - 1;
    }
    virtual Item next() override
    {
        m_currentIndex++;
        return m_bookAggregate->GetAt(m_currentIndex);
    }

private:
    BookAggregate<Item> *m_bookAggregate;
    int m_currentIndex = -1;
};

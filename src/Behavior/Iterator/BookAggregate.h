#pragma once
#include "Aggregate.h"
#include <string>
#include <vector>

template <class Item>
class BookAggregateIterator;

template <class Item>
class BookAggregate : public Aggregate<Item>
{
public:
    BookAggregate(int maxSize)
    {
        m_books.resize(maxSize, std::string(""));
    }
    Iterator<Item> *CreateIterator() override
    {
        return new BookAggregateIterator<Item>(this);
    }

    Item GetAt(int index) const
    {
        return m_books.at(index);
    }
    void append(const Item &book)
    {
        m_books.emplace_back (book);
    }
    int length() const
    {
        return static_cast<int>(m_books.size());
    }

private:
    std::vector<Item> m_books;
};

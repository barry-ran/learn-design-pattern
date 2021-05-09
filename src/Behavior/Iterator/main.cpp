#include "Book.h"
#include "BookAggregate.h"
#include "BookAggregateIterator.h"
#include <iostream>
#include <string>
using std::cerr;
using std::cout;
using std::endl;
using std::string;
int main()
{
    Aggregate<Book> *aggregate = new BookAggregate<Book>(0);
    aggregate->append(Book(string("name1")));
    aggregate->append(Book(string("name2")));
    aggregate->append(Book(string("name3")));
    
    auto itor = aggregate->CreateIterator();
    while (itor->hasNext())
    {
        Book book = itor->next();
        cout << book.GetName() << endl;
    }
    delete aggregate;
    delete itor;
    return 0;
}

#include "SingleTon.h"
#include "ThreeTon.h"

#include <iostream>
#include <string>
using namespace std;
class Apple : public SingleTon<Apple>
{
    friend SingleTon<Apple>;

public:
    void show()
    {
        cout << __FUNCTION__ << endl;
    }
    ~Apple()
    {
        cout << __FUNCTION__ << endl;
    }

protected:
    Apple() {}
};

class Orange : public SingleTon<Orange>
{
    friend SingleTon<Orange>;

public:
    ~Orange()
    {
        cout << __FUNCTION__ << endl;
    }
    void show()
    {
        cout << __FUNCTION__ << endl;
    }

protected:
    Orange()
    {

    }
};

class Banana : public ThreeTon<Banana>
{
    friend class ThreeTon<Banana>;

public:
    void show()
    {
        cout << __FUNCTION__ << endl;
    }
    ~Banana()
    {
        cout << __FUNCTION__ << endl;
    }

protected:
    Banana() {}
};

int main()
{
    Apple::GetInstance().show();
    cout << &Apple::GetInstance() << endl;
    Apple::GetInstance().show();
    cout << &Apple::GetInstance() << endl;

    Orange::GetInstance().show();
    Orange::GetInstance().show();
    Orange::GetInstance().show();

    Banana::GetInstance(0).show();
    cout << &Banana::GetInstance(0) << endl;
    Banana::GetInstance(1).show();
    cout << &Banana::GetInstance(1) << endl;
    Banana::GetInstance(2).show();
    cout << &Banana::GetInstance(2) << endl;
    Banana::GetInstance(3).show();
    cout << &Banana::GetInstance(3) << endl;
    return 0;
}

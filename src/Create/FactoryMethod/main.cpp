#include "WoodenDoorFactory.h"
#include "IronDoorFactory.h"
int main()
{
    IDoorFactory* fac = new WoodenDoorFactory;
    IDoor* door = fac->createDoor();
    door->getDescription();

    IDoorFactory* fac1 = new IronDoorFactory;
    IDoor* door1 = fac1->createDoor();
    door1->getDescription();

    delete door;    
    delete fac;    
    delete door1;    
    delete fac1;
    
    return 0;
}
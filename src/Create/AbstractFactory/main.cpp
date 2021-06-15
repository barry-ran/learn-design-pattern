#include "WoodenDoorFactory.h"
#include "IronDoorFactory.h"
int main()
{
    IDoorFactory* fac = new WoodenDoorFactory;
    IDoor* door = fac->createDoor();
    IDoorFittingExpert* expert = fac->createDoorFittingExpert();
    door->getDescription();
    expert->getAbility();

    IDoorFactory* fac1 = new IronDoorFactory;
    IDoor* door1 = fac1->createDoor();
    IDoorFittingExpert* expert1 = fac1->createDoorFittingExpert();
    door1->getDescription();
    expert1->getAbility();

    delete door;    
    delete fac;    
    delete door1;    
    delete fac1;
    
    return 0;
}
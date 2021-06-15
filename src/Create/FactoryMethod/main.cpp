#include "IDCardFactory.h"
#include "IDCardProFactory.h"
int main()
{
    IFactory *fac = new IDCardFactory;
    IProduct *p = fac->create("tao");    
    p->use();

    IFactory *facPro = new IDCardProFactory;
    IProduct *pPro = fac->create("tao2");
    pPro->use();    

    delete p;    
    delete fac;    
    delete pPro;    
    delete facPro;
    
    return 0;
}
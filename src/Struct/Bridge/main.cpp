#include "Rect.h"
#include "Red.h"
#include <memory>
#include <iostream>

int main(int argc, char **argv)
{
    std::shared_ptr<IColor> color(new Red());
    std::shared_ptr<IShape> shape(new Rect(color.get()));
    std::cout << shape->getName() << std::endl;
    
    return 0;
}

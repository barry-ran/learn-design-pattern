#include "Gamer.h"
#include "Memento.h"
#include "CareTaker.h"
int main()
{
    Gamer g(100);
    // 这里CareTaker作为单状态管理者，也可以根据需要改为多状态管理者
    
    CareTaker ct;
    ct.setMemento(g.createMemento());
    for (int i = 0; i < 100; ++i)
    {
        std::cout << "===== " + i << std::endl;
        std::cout << g.toString() << std::endl;
        g.bet();
        if (g.getMoney() > ct.getMemento().getMoney())
        {
            ct.setMemento(g.createMemento());
            std::cout << "addMoney, save" << std::endl;
        }
        else if (g.getMoney() < ct.getMemento().getMoney() / 2)
        {
            g.restoreMemento(ct.getMemento());
            std::cout << "decMoney, restore" << std::endl;
        }
    }
    return 0;
}
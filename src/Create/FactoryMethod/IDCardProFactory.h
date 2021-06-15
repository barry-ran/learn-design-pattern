#pragma once
#include "IDCardPro.h"
#include "IFactory.h"
#include <string>
#include <vector>
class IDCardProFactory : public IFactory
{
public:
    IProduct *createProduct(const std::string &owner)
    {
        return new IDCardPro(owner);
    }
    void registerProduct(IProduct *pro)
    {
        m_productList.push_back(pro);
    }

private:
    std::vector<IProduct *> m_productList;
};
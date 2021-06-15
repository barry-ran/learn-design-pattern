#pragma once
#include "IProduct.h"
#include <iostream>
#include <string>
class IDCardPro : public IProduct
{
public:
    IDCardPro(const std::string &owner) : m_owner(owner) {}
    void use() override
    {
        std::cout << "use IDCardPro with owner" << m_owner << std::endl;
    }

private:
    std::string m_owner;
};
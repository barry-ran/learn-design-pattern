#pragma once
#include "Visitor.h"
#include <string>
#include <iostream>
#include "File.h"
#include "Directory.h"
class FileCountVisitor : public Visitor
{
public:
    virtual void visit(File *file) override 
    {
        m_fileCount++;
        std::cout << "current file count:" << m_fileCount << std::endl;
    }
    virtual void visit(Directory *dir) override
    {        
        auto entryList = dir->getEntryList();
        for (auto it: entryList)
        {
            it->accept(this);
        }        
    }
private:
    int m_fileCount = 0;
};
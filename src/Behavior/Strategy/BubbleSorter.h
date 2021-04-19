#pragma once
#include "ISortHandle.h"

class BubbleSorter
{
public:
    BubbleSorter(ISortHandle* sortHandle) {
        m_sortHandle = sortHandle;
    }
    virtual ~BubbleSorter() {}
    
    // 控制冒泡排序的核心逻辑，委托ISortHandle去实现不同数据类型的处理
    int sort (void* array, int count) {        
        m_sortHandle->setArray(array, count);
        int length = m_sortHandle->getLength();

        int operations = 0;
        if (length <= 1) {
            return operations;
        }

        for (int nextToLast = length-2; nextToLast >= 0; nextToLast--) {
            for (int index = 0; index <= nextToLast; index++) {
                if (m_sortHandle->outOfOrder(index)) {
                    m_sortHandle->swap(index);
                }
                operations++;
            }            
        }
        return operations;
    }

protected:    
    ISortHandle* m_sortHandle = nullptr;
};
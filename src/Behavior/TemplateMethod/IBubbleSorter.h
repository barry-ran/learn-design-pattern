#pragma once

class IBubbleSorter
{
public:
    virtual ~IBubbleSorter() {}
    // 比较两个相邻元素
    virtual bool outOfOrder(int index) = 0;
    // 交换两个相邻元素
    virtual void swap(int index) = 0;
    
    // 基类控制冒泡排序的核心逻辑，子类去实现不同数据类型的处理
    int doSort () {
        int operations = 0;
        if (m_length <= 1) {
            return operations;
        }

        for (int nextToLast = m_length-2; nextToLast >= 0; nextToLast--) {
            for (int index = 0; index <= nextToLast; index++) {
                if (outOfOrder(index)) {
                    swap(index);
                }
                operations++;
            }            
        }
        return operations;
    }

protected:
    int m_length = 0;
};
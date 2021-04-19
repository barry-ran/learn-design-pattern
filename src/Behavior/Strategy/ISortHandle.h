#pragma once

class ISortHandle
{
public:
    // 比较两个相邻元素
    virtual bool outOfOrder(int index) = 0;
    // 交换两个相邻元素
    virtual void swap(int index) = 0;

    virtual void setArray(void* array, int length) = 0;
    virtual int getLength() = 0;
};
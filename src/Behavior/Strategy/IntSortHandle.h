#pragma once
#include "ISortHandle.h"

class IntSortHandle : public ISortHandle {
public:
    void setArray(void* array, int length) override {
        m_array = (int*)array;
        m_length = length;
    }

    bool outOfOrder(int index) override {
        return m_array[index] > m_array[index+1];
    }

    void swap(int index) override {
        int temp = m_array[index];
        m_array[index] = m_array[index+1];
        m_array[index+1] = temp;
    }

    int getLength() override {
        return m_length;
    }

private:
    int* m_array = nullptr;
    int m_length = 0;
};
#pragma once
#include "IBubbleSorter.h"
class IntBubbleSorter : public IBubbleSorter {
public:
    int sort(int* array, int count) {
        m_array = array;
        m_length = count;
        return doSort();
    }

    bool outOfOrder(int index) override {
        return m_array[index] > m_array[index+1];
    }

    void swap(int index) override {
        int temp = m_array[index];
        m_array[index] = m_array[index+1];
        m_array[index+1] = temp;
    }

private:
    int* m_array = nullptr;    
};
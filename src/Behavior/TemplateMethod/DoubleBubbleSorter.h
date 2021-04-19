#pragma once
#include "IBubbleSorter.h"

class DoubleBubbleSorter : public IBubbleSorter {
public:
    int sort(double* array, int count) {
        m_array = array;
        m_length = count;
        return doSort();
    }

    bool outOfOrder(int index) override {
        return m_array[index] > m_array[index+1];
    }

    void swap(int index) override {
        double temp = m_array[index];
        m_array[index] = m_array[index+1];
        m_array[index+1] = temp;
    }

private:
    double* m_array = nullptr;
};
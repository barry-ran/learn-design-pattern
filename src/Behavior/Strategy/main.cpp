#include <iostream>
using namespace std;

#include "IntSortHandle.h"
#include "DoubleSortHandle.h"
#include "BubbleSorter.h"

int main (int argc, char **argv) {
    // test Int
    int intArray[5] = {2, 3, 8, 1, 4};
    IntSortHandle* intSortHandle = new IntSortHandle();
    BubbleSorter intBubbleSorter(intSortHandle);
    intBubbleSorter.sort(intArray, 5);    
    delete intSortHandle;

    for (int i=0; i<5; i++) {
        cout << intArray[i] << " ";
    }
    cout << endl;

    // test Double
    double doubleArray[5] = {2.5, 3.5, 8.5, 1.5, 4.5};
    DoubleSortHandle* doubleSortHandle = new DoubleSortHandle();
    BubbleSorter doubleBubbleSorter(doubleSortHandle);
    doubleBubbleSorter.sort(doubleArray, 5);
    delete doubleSortHandle;

    for (int i=0; i<5; i++) {
        cout << doubleArray[i] << " ";
    }
    cout << endl;

    return 0;
}

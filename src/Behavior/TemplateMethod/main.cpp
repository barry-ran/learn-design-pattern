#include <iostream>
using namespace std;

#include "IntBubbleSorter.h"
#include "DoubleBubbleSorter.h"

int main (int argc, char **argv) {
    // test IntBubbleSorter
    int intArray[5] = {2, 3, 8, 1, 4};
    IntBubbleSorter* intSort = new IntBubbleSorter();
    intSort->sort(intArray, 5);
    delete intSort;

    for (int i=0; i<5; i++) {
        cout << intArray[i] << " ";
    }
    cout << endl;

    // test DoubleBubbleSorter
    double doubleArray[5] = {2.5, 3.5, 8.5, 1.5, 4.5};
    DoubleBubbleSorter* doubleSort = new DoubleBubbleSorter();
    doubleSort->sort(doubleArray, 5);
    delete doubleSort;

    for (int i=0; i<5; i++) {
        cout << doubleArray[i] << " ";
    }
    cout << endl;

    return 0;
}

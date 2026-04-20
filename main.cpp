#include <iostream>

#include "ordination.h"
#include "recursion.h"

using namespace std;

int main(int argc, char const* argv[]) {
    // Recursão:

    /*
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int lastElement = (sizeof(array) / sizeof(array[0])) - 1;

    invert(array, 0, lastElement);
    for (int number : array) cout << number << " ";
    cout << endl;

    torreHanoi(5, 1, 2, 3);
    */

    // Ordenação:

    int array[] = {5, 2, 13, 7, -3, 4, 15, 10, 1, 6};
    int length = sizeof(array) / sizeof(array[0]);

    printArray(array, length, "Array não ordenado: ");

    // bubbleSort(array, length);
    // inserSort(array, length);
    // selectSort(array, length);

    mergeSort(array, 0, length - 1);

    printArray(array, length, "Array ordenado: ");

    return 0;
}
#include "recursion.h"

#include <iostream>

using namespace std;

void swap(int* array, int a, int b) {
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}

void invert(int* array, int initial, int end) {
    if (initial >= end)
        return;
    else {
        swap(array, initial, end);
        invert(array, ++initial, --end);
    }
}

void torreHanoi(int n, int source, int auxiliary, int target) {
    if (n == 1) {
        cout << "Mover disco da torre " << source << " para a torre " << target
             << endl;
        return;
    }
    torreHanoi(n - 1, source, target, auxiliary);
    cout << "Mover disco da torre " << source << " para a torre " << target
         << endl;
    torreHanoi(n - 1, auxiliary, source, target);
}
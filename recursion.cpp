#include "recursion.h"

#include <iostream>
#include <vector>

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

void printArray(int* array, int length, string msg = "") {
    cout << msg << "[ ";
    for (int i = 0; i < length; i++) cout << array[i] << " ";
    cout << "] " << endl;
}

void bubbleSort(int* array, int length) {
    for (int i = 0; i < length - 1; i++) {
        bool modified = false;

        for (int j = 0; j < length - i - 1; j++)
            if (array[j] > array[j + 1]) {
                swap(array, j, j + 1);
                modified = true;
            }

        if (!modified) break;
    }
}

void inserSort(int* array, int length) {
    for (int i = 1; i < length; i++) {
        int item = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > item) {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = item;
    }
}
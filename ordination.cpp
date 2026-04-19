#include <iostream>
using namespace std;

#include "ordination.h"
#include "util.h"

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

void selectSort(int* array, int length) {
    for (int i = 0; i < length - 1; i++) {
        int mindIndex = i;

        for (int j = i + 1; j < length; j++)
            if (array[j] < array[mindIndex]) mindIndex = j;

        if (mindIndex != i) swap(array, i, mindIndex);
    }
}

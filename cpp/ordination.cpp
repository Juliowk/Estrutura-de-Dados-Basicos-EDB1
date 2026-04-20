#include <iostream>
using namespace std;

#include "headers/ordination.h"
#include "headers/util.h"

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

void merge(int* array, int start, int half, int end) {
    int elementsOnLeft = half - start + 1;
    int elementsOnRight = end - half;

    int leftSide[elementsOnLeft];
    int rightSide[elementsOnRight];

    for (int i = 0; i < elementsOnLeft; i++) leftSide[i] = array[start + i];

    for (int j = 0; j < elementsOnRight; j++)
        rightSide[j] = array[half + 1 + j];

    int i = 0, j = 0;
    int k = start;

    while (i < elementsOnLeft && j < elementsOnRight) {
        if (leftSide[i] <= rightSide[j]) {
            array[k] = leftSide[i];
            i++;
        } else {
            array[k] = rightSide[j];
            j++;
        }
        k++;
    }

    while (i < elementsOnLeft) {
        array[k] = leftSide[i];
        i++;
        k++;
    }

    while (j < elementsOnRight) {
        array[k] = rightSide[j];
        j++;
        k++;
    }
}

void mergeSort(int* array, int start, int end) {
    int half = (start + end) / 2;

    if (start < end) {
        mergeSort(array, start, half);
        mergeSort(array, half + 1, end);

        merge(array, start, half, end);
    }
}

int partition(int* array, int start, int end) {
    int pivot = array[end];
    int i = start - 1;

    for (int j = start; j < end; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(array, i, j);
        }
    }

    swap(array, i + 1, end);
    return i + 1;
}

void quickSort(int* array, int start, int end) {
    if (start < end) {
        int pivot = partition(array, start, end);
        quickSort(array, start, pivot - 1);
        quickSort(array, pivot + 1, end);
    }
}
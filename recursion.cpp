#include <iostream>

#include "recursion.h"

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
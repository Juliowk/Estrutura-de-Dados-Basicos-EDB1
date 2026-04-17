#include <iostream>

#include "recursion.h"

using namespace std;

int main(int argc, char const* argv[]) {
  
  int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int lastElement = (sizeof(array) / sizeof(array[0])) - 1;

  invert(array, 0, lastElement);
  for (int number : array) cout << number << " ";

  return 0;
}
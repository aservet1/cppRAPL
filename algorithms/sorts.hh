#ifndef SORTS_HH
#define SORTS_HH

#include <cassert>
#include <iostream>
#include <iomanip>

const int THRESHOLD = 10;

template <typename E>
static void swap(E a[], int i, int j){
  E t = a[i];
  a[i] = a[j];
  a[j] = t;
}

template <typename E>
void genRandomArray(E *arr, int size){
  srand(time(0));
  for(int i = 0 ; i < size; i++){
    arr[i] = (E)(rand()%200);
  }
}

template <typename E>
static bool isSorted(E a[], int n){
  for (int i = 1; i < n; ++i) {
    if (a[i] < a[i - 1]) return 0;
  }
  return 1;
}


#endif

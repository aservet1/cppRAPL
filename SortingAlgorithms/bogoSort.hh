#ifndef BOGO_SORT_HH
#define BOGO_SORT_HH

#include <iostream>
#include <ctime>
#include "sorts.hh"

template <typename E>
static void shuffle(E arr[], int length){
  for (int n = 0; n < length*2; n++){
    int i = rand()%length;
    int j = rand()%length;
    swap(arr, i, j);
  }
}

template <typename E>
void bogoSort(E arr[], int length){
  while(!isSorted(arr,length)){
    shuffle(arr,length);
  }
}

#endif

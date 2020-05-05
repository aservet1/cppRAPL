#ifndef BOGO_SORT_HH
#define BOGO_SORT_HH

#include <iostream>
#include <ctime>

template <typename E>
static bool isSorted(E arr[], int length){
  for (int i = 1; i < length; i++){
    if (arr[i] < arr[i-1]){
      return false;
    }
  }
  return true;
}

template <typename E>
static void swap(E arr[], int i, int j){
  E temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

template <typename E>
static void shuffle(E arr[], int length){
  for (int n = 0; n < length*2; n++){
    int i = rand()%length
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

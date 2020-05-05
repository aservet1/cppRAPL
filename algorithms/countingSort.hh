#ifndef COUNTING_SORT_HH
#define COUNTING_SORT_HH

#include <iostream>
#include <cfloat>
#include <cmath>

#define precision(n) pow(10,n-1)

template <typename E>
static E findMax(E arr[], int length){
  E max = -9999999;
  for (int i = 0; i < length; i++)
    if (arr[i] > max)
      max = arr[i];
  return max;
}

template <typename E>
static int hash(E d){
  return d*100000; //turn double into int
}

template <typename E>
static E unhash(int i){
  E d = (E)i;
  return d/10000;
}

template <typename E>
void countingSort(E arr[], int length){
  E max = findMax(arr, length);
  int buckets_length = hash(max) + 1;
  int buckets[buckets_length];
  for (int i = 0; i < buckets_length; i++){
    buckets[i] = 0;
  }
  for (int i = 0; i < length; i++){
    int index = hash(arr[i]);
    buckets[index] += 1;
  }
  int arr_i = 0;
  for (int i = 0; i < buckets_length; i++){
    while (buckets[i] != 0){
      arr[arr_i++] = unhash(i);
      buckets[i] -= 1;
    }
  }
}

#endif

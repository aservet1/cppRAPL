#ifndef INSERTION_SORT_HH
#define INSERTION_SORT_HH

#include "sorts.hh"

template <typename E>
void insertionSort(E a[], int n){
  for (int i = 1; i < n; ++i) {
    assert(isSorted(a, i) && "prefix not sorted");
    //insert i'th record into sorted portion
    for (int j = i; (j > 0) && (a[j] < a[j - 1]); --j) {
      swap(a, j, j - 1);
    }
  }
}

#endif

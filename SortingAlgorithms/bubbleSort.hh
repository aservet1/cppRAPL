#ifndef BUBBLE_SORT_HH
#define BUBBLE_SORT_HH

#include "sorts.hh"

template <typename E>
void bubbleSort(E a[], int n){
  for (int i = 0; i < n - 1; ++i) {
    assert(isSorted(a, i) && "prefix not sorted");
    for (int j = n - 1; j > i; --j) {
      if (a[j] < a[j - 1]) swap(a, j, j - 1);
    }
  }
}

#endif

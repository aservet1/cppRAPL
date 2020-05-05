#include "sorts.hh"

template <typename E>
void selectionSort(E a[], int n)
{
  for (int i = 0; i < n - 1; ++i) {
    assert(isSorted(a, i) && "prefix not sorted");
    int minIndex = i;
    for (int j = n - 1; j > i; --j) {
      //find for min value in rest of array
      if (a[j] < a[minIndex]) minIndex = j;
    }
    swap(a, i, minIndex);
  }
}
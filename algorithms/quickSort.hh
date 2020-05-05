#include "sorts.hh"

#ifndef QUICK_SORT_HH
#define QUICK_SORT_HH

template <typename E>
static int findPivot(E a[], int i, int j){
  return (i+j)/2;
}


template <typename E>
static int partition(E a[], int lo, int hi){
  E pivot = a[hi];
	int pIndex = lo;
	for (int i = lo; i < hi; i++)
	{
		if (a[i] <= pivot) swap(a, i, pIndex++);
	}
	swap (a, pIndex, hi);
	
	return pIndex;
}

template <typename E>
static void qsort(E a[], int lo, int hi){
  if(lo >= hi)
		return;
	int pivot = partition(a, lo, hi);
	qsort(a, lo, pivot - 1);
	qsort(a, pivot + 1, hi);
}

template <typename E>
void quickSort(E a[], int n){
  qsort(a, 0, n - 1);
}

template <typename E>
static void quickSortOpt(E a[], int lo, int hi){
  if (hi - lo + 1<= THRESHOLD){
    insertionSort(&a[lo], hi - lo + 1);
    break;
  }
  int pivotindex = findPivot(a, lo, hi);
  swap(a, pivotindex, hi);
  int k = partition(a, lo, hi-1, a[hi]);
  swap(a, k, hi);
  qsort_optimized(a, lo, k - 1);
  qsort_optimized(a, k + 1, hi);
}

template <typename E>
void quickSortOpt(E a[], int n){
  qsort_optimized(a, 0, n);
}






#endif

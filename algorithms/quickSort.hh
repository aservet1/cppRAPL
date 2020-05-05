#include "sorts.hh"

#ifndef QUICK_SORT_HH
#define QUICK_SORT_HH


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
static void qsort_optimized(E a[], int lo, int hi){
  while (lo < hi) 
	{
		// do insertion sort if 10 or smaller
		if(hi - lo + 1 < 10)
		{
			insertionSort(a, hi - lo + 1);
			break;
		}
		else 
		{
			int pivot = partition(a, lo, hi);
			
			// tail call optimizations - recur on smaller sub-array
			if (pivot - lo < hi - pivot) {
				qsort_optimized(a, lo, pivot - 1);
				lo = pivot + 1;
			} else {
				qsort_optimized(a, pivot + 1, hi);
				hi = pivot - 1;
			}
		}
	}	
}

template <typename E>
void quickSortOpt(E a[], int n){
  qsort_optimized(a, 0, n);
}






#endif
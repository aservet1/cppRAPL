#include "sorts.hh"

#ifndef QUICKSORT_HH
#define QUICKSORT_HH
static int findPivot(int a[], int i, int j){
  return (i+j)/2;
}

static int partition(int a[], int lo, int hi, int pivot){
  while (lo <= hi) { //while interval is non-empty
    while (a[lo] < pivot) ++lo;
    while ((hi >= lo) && (a[hi] >= pivot)) --hi;
    if (hi > lo) swap(a, lo, hi);
  }
  return lo;
}

static void qsort(int a[], int lo, int hi){
  if (hi - lo < 1) return;
  int pivotindex = findPivot(a, lo, hi);
  swap(a, pivotindex, hi);
  int k = partition(a, lo, hi-1, a[hi]);
  swap(a, k, hi);
  qsort(a, lo, k - 1);
  qsort(a, k + 1, hi);
}


void quickSort(int a[], int n){
  qsort(a, 0, n - 1);
}

static void qsort_optimized(int a[], int lo, int hi){
  if (hi - lo + 1<= 10) insertionSort(&a[lo], hi - lo + 1);
  int pivotindex = findPivot(a, lo, hi);
  swap(a, pivotindex, hi);
  int k = partition(a, lo, hi-1, a[hi]);
  swap(a, k, hi);
  qsort(a, lo, k - 1);
  qsort(a, k + 1, hi);
}

void quickSort_optimized(int a[], int n){
  qsort_optimized(a, 0, n - 1);
}

#endif
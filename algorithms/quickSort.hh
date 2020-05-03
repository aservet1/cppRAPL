#include "sorts.hh"

#ifndef QUICK_SORT_HH
#define QUICK_SORT_HH

template <typename E>
static int findPivot(E a[], int i, int j){
  return (i+j)/2;
}

template <typename E>
static int partition(E a[], int lo, int hi, int pivot){
  while (lo <= hi){
    while (a[lo] < pivot) ++lo;
    while ((hi >= lo) && (a[hi] >= pivot)) --hi;
    if (hi > lo) swap(a, lo, hi);
  }
  return lo;
}

template <typename E>
static void qsort(E a[], int lo, int hi){
  if (hi - lo < 1) return;
  int pivotindex = findPivot(a, lo, hi);
  swap(a, pivotindex, hi);
  int k = partition(a, lo, hi-1, a[hi]);
  swap(a, k, hi);
  qsort(a, lo, k - 1);
  qsort(a, k + 1, hi);
}

template <typename E>
void quickSort(E a[], int n){
  qsort(a, 0, n - 1);
}

template <typename E>
static void qsort_optimized(E a[], int lo, int hi){
  if (hi - lo + 1<= THRESHOLD) insertionSort(&a[lo], hi - lo + 1);
  int pivotindex = findPivot(a, lo, hi);
  swap(a, pivotindex, hi);
  int k = partition(a, lo, hi-1, a[hi]);
  swap(a, k, hi);
  qsort(a, lo, k - 1);
  qsort(a, k + 1, hi);
}

template <typename E>
void quickSort_optimized(E a[], int n){
  qsort_optimized(a, 0, n - 1);
}

#endif
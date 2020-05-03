#ifndef MERGE_SORT_HH
#define MERGE_SORT_HH

#include <iostream>

#include <cassert>
#include <cstdlib>
#include <cstring>

#include "sorts.hh"


//.beginMSort
//sort a[lo, hi) using temp[] as temporary storage
template <typename E>
static void msort(E a[], E temp[], int lo, int hi) {
  if (hi - lo < 2) return; //empty or single element
  int mid = (lo + hi)/2;   //select midpoint
  msort(a, temp, lo, mid); //mergesort lo half
  msort(a, temp, mid, hi); //mergesort hi half
  
  for (int i = lo; i < hi; ++i) {
    //copy subarray to temp
    temp[i] = a[i];
  }

  //.beginMerge1
  //merge temp[] subarrays back to a[]
  int i1 = lo;
  int i2 = mid;
  for (int dest = lo; dest < hi; ++dest) {
    if (i1 == mid) {
      //left sublist exhausted
      a[dest] = temp[i2++];
    }
    else if (i2 == hi) {
      //right sublist exhausted 
      a[dest] = temp[i1++];
    }
    //.endMerge1
    else if (temp[i1] <= temp[i2]) {
      //smaller value in i1
      a[dest] = temp[i1++];
    }
    else {
      //get smaller value from i2
      a[dest] = temp[i2++];
    }
  }   
}
//.endMerge2

//.beginMergeSort
template <typename E>
void mergeSort(E a[], int n) 
{
  E* temp = new E[n];
  msort(a, temp, 0, n);
  delete temp;
}
//.endMergeSort

//.beginMSort Optimized
//sort a[lo, hi) using temp[] as temporary storage
template <typename E>
static void msortOpt(E a[], E temp[], int lo, int hi) {
  if ( (hi - lo) < THRESHOLD) {
  	insertionSort(&a[lo], hi - lo);
  	return;
  } 
  int mid = (lo + hi)/2;   //select midpoint
  msort(a, temp, lo, mid); //mergesort lo half
  msort(a, temp, mid, hi); //mergesort hi half
  
  for (int i = lo; i < mid; ++i) { temp[i] = a[i]; }
  for (int j = 0;j < hi - mid; ++j){  //reversed copy
  	temp[hi - j - 1] = a[mid + j];
  }
  for (int i1 = lo, i2 = hi - 1, dest = lo; dest < hi; ++dest){ //optimized range
  	if (temp[i1] < temp[i2]) {
		a[dest] = a[i1++];
	}else{ 
		a[dest] = a[i2--];
	}
  }
}
//.endMerge2

//.beginMergeSort Optimized
template <typename E>
void mergeSortOpt(E a[], int n) 
{
  E* temp = new E[n];
  msort(a, temp, 0, n);
  delete temp;
}
//.endMergeSort

#endif

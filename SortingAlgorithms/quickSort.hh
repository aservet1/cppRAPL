#ifndef QUICK_SORT_HH
#define QUICK_SORT_HH

#include "sorts.hh"
#include "insertionSort.hh"


template <typename E>
static int findPivot(E a[], int i, int j)
{
  return (i+j)/2;
}
//.endPivot

//.beginPartition
/** partition a [lo, hi] into < pivot left sub-array and >= pivot
 *  right sub-array, returning index of first position in right
 *  sub-array 
 */
template <typename E>
static int partition(E a[], int lo, int hi, int pivot) {
  while (lo <= hi) { //while interval is non-empty
    while (a[lo] < pivot) {
      //loop terminates because pivot is at a[hi + 1]
      ++lo;
    }
    while ((hi >= lo) && (a[hi] >= pivot)) --hi;
    if (hi > lo) swap(a, lo, hi); //swap out-of-place values
  }
  return lo;            // Return first position in right partition
}
//.endPartition.

//.beginQSort.
/** sort a [lo, hi] */
template <typename E>
static void
qsort(E a[], int lo, int hi)
{
  if (hi - lo < 1) return;
  int pivotindex = findPivot(a, lo, hi);  // Pick a pivot
  swap(a, pivotindex, hi);           // Stick pivot at end
  // k will be the first position in the right subarray
  int k = partition(a, lo, hi-1, a[hi]);
  swap(a, k, hi);       // Put pivot in place
  qsort(a, lo, k - 1);  // Sort left partition
  qsort(a, k + 1, hi);  // Sort right partition
}
//.endQSort

//.beginQuickSort.
/** sort a [0, n) */
template <typename E>
void
quickSort(E a[], int n)
{
  qsort(a, 0, n - 1);
}

#endif

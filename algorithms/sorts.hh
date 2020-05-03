#ifndef SORTS_HH
#define SORTS_HH

const int THRESHOLD = 10;

<<<<<<< HEAD
template <typename E>
static void swap(E a[], int i, int j){
  E t = a[i];
=======
static void
swap(int a[], int i, int j)
{
  int t = a[i];
>>>>>>> 7abfb776f8311b3b97aceeb110006405ca0d435b
  a[i] = a[j];
  a[j] = t;
}

template <typename E>
static bool isSorted(int a[], int n){
  for (int i = 1; i < n; ++i) {
    if (a[i] < a[i - 1]) return 0;
  }
  return 1;
}

template <typename E>
void bubbleSort(E a[], int n){
  for (int i = 0; i < n - 1; ++i) {
    assert(isSorted(a, i) && "prefix not sorted");
    for (int j = n - 1; j > i; --j) {
      if (a[j] < a[j - 1]) swap(a, j, j - 1);
    }
  }
}

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

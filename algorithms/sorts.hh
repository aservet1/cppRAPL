#ifndef INSERTION_SORT_HH
	#define INSERTION_SORT_HH

const int THRESHOLD = 10;

static void
swap(int a[], int i, int j)
{
  int t = a[i];
  a[i] = a[j];
  a[j] = t;
}

static bool
isSorted(int a[], int n)
{
  for (int i = 1; i < n; ++i) {
    if (a[i] < a[i - 1]) return 0;
  }
  return 1;
}

//.beginBubbleSort.
void
bubbleSort(int a[], int n)
{
  for (int i = 0; i < n - 1; ++i) {
    assert(isSorted(a, i) && "prefix not sorted");
    for (int j = n - 1; j > i; --j) {
      if (a[j] < a[j - 1]) swap(a, j, j - 1);
    }
  }
}
//.endBubbleSort.

//.beginInsertionSort.
void
insertionSort(int a[], int n)
{
  for (int i = 1; i < n; ++i) {
    assert(isSorted(a, i) && "prefix not sorted");
    //insert i'th record into sorted portion
    for (int j = i; (j > 0) && (a[j] < a[j - 1]); --j) {
      swap(a, j, j - 1);
    }
  }
}
//.endInsertionSort.

#endif

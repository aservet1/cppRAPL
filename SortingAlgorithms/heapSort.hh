#ifndef HEAP_SORT_HH
#define HEAP_SORT_HH

#include <iostream>
#include <iomanip>
#include <cassert>
#include <cctype>
#include <cstdlib>
#include <cstring>


template <typename E>
class MaxHeap {
public:
  MaxHeap(E heapArray[], int nElements, int size) :
    heap(heapArray), nAlloc(size), nElements(nElements)
  {
    buildHeap();
  }

  void enqueue(E value) {
    assert(nElements < nAlloc && "heap is full");
    heap[nElements++] = value; //add value at end
    for (int pos = nElements - 1; //pos of added value
	    pos != 0 && heap[pos] > heap[parent(pos)];
	    pos = parent(pos)) {
      swap(pos, parent(pos));
    }
  }

  E dequeue() {
    assert(nElements > 0 && "heap is empty");
    E value = heap[0];
    heap[0] = heap[nElements - 1]; //put last element at root
    --nElements; //delete it
    if (nElements > 0) siftDown(0);  //move it to correct position
    return value;
  }

  int size() { return nElements; }

private:
  E* heap; 
  int nAlloc;    //max # of elements in heap
  int nElements; //# of currently allocated element in heap

  /** Heapify heap [0, nElements). */
  void buildHeap() {
    //move internal nodes down if necessary
    for (int i = nElements/2 - 1; i >= 0; --i) {
      siftDown(i);
    }
  }

  /** Move element at pos down in the tree until it is greater
   *  than either of its two children.
   *  When it is necessary to move down, prefer to move down
   *  into subtree with the greater root. 
   */
  void siftDown(int pos) {
    assert(0 <= pos && pos < nElements);
    while (!isLeaf(pos)) {
      int leftKidPos = leftChild(pos);
      //there must be a left kid since pos is not a leaf
      assert(0 <= leftKidPos && leftKidPos < nElements);
      int rightKidPos = rightChild(pos);
      int maxKidPos =
	      (rightKidPos >= 0 && heap[rightKidPos] > heap[leftKidPos])
	      ? rightKidPos
	      : leftKidPos;
      if (heap[pos] >= heap[maxKidPos]) return;
      swap(pos, maxKidPos);
      pos = maxKidPos;
    }
  }

  void swap(int pos1, int pos2) {
    assert(0 <= pos1 && pos1 < nElements);
    assert(0 <= pos2 && pos2 < nElements);
    E tmp = heap[pos1];
    heap[pos1] = heap[pos2];
    heap[pos2] = tmp;
  }

  //tree accessors
  bool isLeaf(int pos) const {
    return (pos >= nElements/2) && (pos < nElements);
  }

  int leftChild(int pos) {
    return (2*pos + 1 < nElements) ? 2*pos + 1 : -1;
  }

  int rightChild(int pos) {
    return (2*pos + 2 < nElements) ? 2*pos + 2 : -1;
  }

  int parent(int pos) {
    return (pos > 0) ? (pos - 1)/2 : -1;
  }
  
  template<class T>
  friend std::ostream& operator<<(std::ostream& out, const MaxHeap<T>& heap);
};

template<class T>
std::ostream&
operator<<(std::ostream& out, const MaxHeap<T>& heap) {
  out << "[ ";
  for (int i = 0; i < heap.nElements; i++) {
    out << heap.heap[i] << " ";
  }
  out << "]";
  return out;
}

template <typename E>
void heapSort(E a[], int n){
  MaxHeap<E> heap = MaxHeap<E>(a, n, n);
  for(int i = 0; i < n; ++i){
    E max = heap.dequeue();
    a[n- 1 - i] = max;
  }
}

template <typename E>
void printArray(E a[], int size){
  for (int i=0;i<size;++i){
    std::cout << a[i] << " ";
  }
  std::cout << std::setprecision(10) << std::endl;
}

#endif 

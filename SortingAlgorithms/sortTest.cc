#include "heapSort.hh"
#include "mergeSort.hh"
#include "quickSort.hh"

enum { MAX_HEAP_SIZE = 16 };

/** prefix of  argv[] elements which are ints used to 
 *  to initialize heap; if remaining arg starts is
 *  +VAL, then VAL enqueued onto heap; if "-", then
 *  a value is dequeued from heap.
 */

int main(void) {
  /*if (argc < 2) {
    std::cerr << "usage: " << argv[0] << " INT..." << std::endl;
    exit(1);							       
  }*/
  std::ostream& out = std::cout;
  /*double array[MAX_HEAP_SIZE];
  int argvIndex;
  int nElements = 0;
  for (argvIndex = 1; argvIndex < argc; argvIndex++) {
    const char* arg = argv[argvIndex];
    if (!isdigit(arg[0])) break;
    assert(nElements < MAX_HEAP_SIZE && "too many initial elements");
    array[nElements++] = atof(arg);
  }*/
 

  int nElements = 100;
  double *array = new double[nElements];
  genRandomArray(array, nElements);
  out << "initial array: " << std::endl;
  printArray(array, nElements); 
  quickSortOpt (array, nElements);
  out << "sorted array: " << std::endl;
  printArray(array, nElements);
  delete[] array;
  return 0;
}

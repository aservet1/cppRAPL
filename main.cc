#include <cstdlib>
#include <ctime>

#include "algorithms/sorts.hh"
#include "algorithms/mergeSort.hh"
#include "algorithms/heapSort.hh"
#include "algorithms/quickSort.hh"
#include "algorithms/bubbleSort.hh"
#include "algorithms/insertionSort.hh"
#include "algorithms/countingSort.hh"
#include "algorithms/bogoSort.hh"
#include "energyReadings.hh"
#include "stamp.hh"
#include "helperFunctions.hh"

#define DELAY 2

int main(int argc, char *argv[]){
  ProfileInit();

  int numberOfSorts = 8; //9 when including bogoSort!

  void (*fns[])(double[],int ) = {/*bogoSort,*/ bubbleSort, insertionSort, countingSort, mergeSort, mergeSortOpt, quickSort, quickSortOpt, heapSort};

  const char *fnNames[] = {/*"Bogo Sort",*/ "Bubble Sort", "Insertion Sort", "Counting Sort", "Merge Sort", "Optimized Mergesort", "Quicksort", "Optimized Quicksort", "Heap Sort"};
	
  std::cout << "len of names " << sizeof(fnNames)/sizeof(char*) << std::endl;

  int sizes[] = {10, 100, 1000, 10000, 1000000};
  for(int size : sizes){
    //EnergyArrays *arrays = getEnergySamples(size, DELAY);
    double *data = new double[size];
    genRandomArray(data, size);
    double *copy = new double[size];
    for(int i = 0; i < numberOfSorts; i++){
      if((i == 0 || i == 1) && size > 1000){
        continue;
      }
      makeCopy(copy, data, size);
      Stamp start;
      fns[i](copy, size);
      Stamp stop;
      auto time_elapsed = stop.timeDifference(start) / 1000;
      std::vector<double> energy_diff = stop.energyDifference(start);
      std::cout << fnNames[i] << " " << size << " " << time_elapsed << " " << std::endl;
      //printVector(energy_diff);
    }
    delete[] copy;
    delete[] data;
    //delete arrays;
  }

  ProfileDealloc();

  return 0;
}

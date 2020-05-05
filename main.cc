#include <cstdlib>
#include <ctime>
#include <iomanip>
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

  void (*fns[])(double[],int ) = {/*bogoSort,*/ bubbleSort, insertionSort, /*countingSort,*/ mergeSort, mergeSortOpt,/* quickSort, quickSortOpt,*/ heapSort};

  const char *fnNames[] = {/*"Bogo_Sort",*/ "Bubble_Sort", "Insertion_Sort" /*"Counting_Sort"*/, "Merge_Sort", "Optimized_Mergesort", /*"Quicksort", "Optimized_Quicksort"*/ "Heap_Sort"};
	
  //std::cout << "len of names " << sizeof(fnNames)/sizeof(char*) << std::endl;

  int sizes[] = {10, 20, 30, 40 ,50 , 60, 70, 80, 90, 100,200, 300, 400, 500, 600, 700, 800, 900, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000};//, 10000, 50000, 1000000};
  for(int size : sizes){
    //EnergyArrays *arrays = getEnergySamples(size, DELAY);
    double *data = new double[size];
    genRandomArray(data, size);
    double *copy = new double[size];
    for(int i = 0; i < 5; i++){
      if((i == 0 || i == 1) && size > 50000){
        continue;
      }
      makeCopy(copy, data, size);
      Stamp start;
      fns[i](copy, size);
      Stamp stop;
      double time_elapsed = stop.timeDifference(start) / 1000000;
      std::vector<double> energy_diff = stop.energyDifference(start);
      std::cout << fnNames[i] << " " << size << " " << time_elapsed << " " ;
      printVector(energy_diff);
    }
    delete[] copy;
    delete[] data;
    //delete arrays;
  }
  for(int i = 0; i < 20; i++){
	  
  }

  ProfileDealloc();

  return 0;
}

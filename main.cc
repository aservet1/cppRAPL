#include "main.hh"
#include "algorithms/sorts.hh"
#include "algorithms/mergeSort.hh"
#include "algorithms/heapSort.hh"
#include "algorithms/quickSort.hh"
#include "algorithms/countingSort.hh"
#include "algorithms/bogoSort.hh"

#define DELAY 2


int main(int argc, char *argv[])
{
	ProfileInit();
	

	void (*fns[])(double[],int ) = {/*bogoSort,*/ bubbleSort, insertionSort, countingSort, mergeSort, mergeSortOpt, quickSort, quickSort_optimized};

	auto fnNames = {/*"Bogo Sort",*/ "Bubble Sort", "Insertion Sort", "Counting Sort", "Merge Sort", "Optimized Mergesort", "Quicksort", "Optimized Quicksort"};
	
	std::cout << "len of names " << sizeof(fnNames)/sizeof(char*) << std::endl;

	int sizes[] = {10, 100, 1000};
	for(int size : sizes){
		EnergyArrays *arrays = getEnergySamples(size, DELAY);
		for(int i = 0; i < sizeof(fnNames)/sizeof(char*); i++){
			Stamp start;
			fns[i](arrays->core, arrays->n);
			Stamp stop;
			auto time_elapsed = stop.timeDifference(start);
			std::vector<double> energy_diff = stop.energyDifference(start);
			std::cout << fnNames[i] << " " << size << " " << time_elapsed;
			printVector(energy_diff);
		}
	}

	Stamp start;
	Stamp stop;

	
	

	std::cout << "time " << time_elapsed << std::endl;
	printVector(energy_diff);
	
	ProfileDealloc();

	return 0;
}

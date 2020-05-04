#include "main.hh"

int main(int argc, char *argv[])
{
	ProfileInit();
	//auto e = getEnergySamples(100000,2);
	//e->printArrays();
	void (*fns[])(double[],int ) = {bubbleSort, insertionSort, mergeSort, mergeSortOpt, quickSort, quickSort_optimized};
	auto fnNames = {"Bubble Sort", "Insertion Sort", "Merge Sort", "Optimized Mergesort", "Quicksort", "Quicksort Optimized"};
	
	for(auto fn : fns){
		fn()
	}

	ProfileDealloc();
	return 0;
}
#include "main.hh"

int main(int argc, char *argv[])
{
	ProfileInit();
	Stamp start;

	
	//auto e = getEnergySamples(100000,2);
	//e->printArrays();
	void (*fns[])(double[],int ) = {bubbleSort, insertionSort, mergeSort, mergeSortOpt, quickSort, quickSort_optimized};
	auto fnNames = {"Bubble Sort", "Insertion Sort", "Merge Sort", "Optimized Mergesort", "Quicksort", "Quicksort Optimized"};
	

	Stamp stop;

	auto time_elapsed = stop.timeDifference(start);
	std::vector<double> energy_diff = stop.energyDifference(start);

	std::cout << "time " << time_elapsed << std::endl;
	printVector(energy_diff);
	
	ProfileDealloc();

	return 0;
}

#include "main.hh"



int main(int argc, char *argv[])
{
	ProfileInit();
	Stamp start;
	std::cout << "Start stamp" << std::endl;

	//auto e = getEnergySamples(100000,2);
	//e->printArrays();
	void (*fns[])(double[],int ) = {bubbleSort, insertionSort, mergeSort, mergeSortOpt, quickSort, quickSort_optimized};

	auto fnNames = {"Bubble Sort", "Insertion Sort", "Merge Sort", "Optimized Mergesort", "Quicksort", "Quicksort Optimized"};
	for(const char* name : fnNames){
		std::cout << name << std::endl;
	}
	
	
	this_thread::sleep_for(chrono::milliseconds(1));
	Stamp stop;
	std::cout << "stop stamp" << std::endl;

	auto time_elapsed = stop.timeDifference(start);
	std::cout << "stop timeDifference" << std::endl; 

	std::vector<double> energy_diff = stop.energyDifference(start);

	std::cout << "time " << time_elapsed << std::endl;
	printVector(energy_diff);
	std::cout << "print vector" << std::endl;
	
	ProfileDealloc();
	return 0;
}

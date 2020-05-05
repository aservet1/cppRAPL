# Time and Energy Analysis of Sorting Algorithms

This application measures the runtime and energy consumption of sorting algorithms in C++

## Sorting algorithms analyzed
+ Bubble Sort
+ Insertion Sort
+ Selection Sort
+ Merge Sort
+ Merge Sort Optimized
+ Quicksort
+ Counting Sort
+ Bogosort

## How are we measuring power consumption?
The RAPL library, implemented in C, is adapted from an independent research project, [jRAPL](https://github.com/aservet1/jRAPL), that Rutvik and Alejandro are working on for Professor Yu David Liu.

RAPL stands for Running Average Power Limit, a way of monitoring and controlling a computer's energy levels. It works on Intel processors by reading and writing the Model Specific Registers (MSRs). In this project, we only directly access one function from the library, EnergyStatCheck(), which returns total energy consumption. We call the function before and after running our sorting algorithms and take the difference in readings.
EnergyStatCheck() returns energy readings for three different power domains: DRAM, CPU, and Package. Package is the entire CPU socket. Our algorithms will therefore be measured with respect to energy consumption in each of these three power domains.
   ##### System requirements
   The energy reading utility currently only works for Intel processors on Linux systems. Root access required to run the program.

## How are we measuring runtime?
Using std::chrono we can timestamp before and after a function runs and take the difference to measure the elapsed time.

## How are we generating data?
We are reading the floating point energy values n times to collect the readings for an array of size n. Though this is not absolutely necessary (random number generation would have sufficed), we thought it would be cool to also use the energy reading collection tool to generate the data. It helps Rutvik and Alejandro's research efforts to get comfortable gathering energy data and packaging it up for further analysis.

## Performance analysis implementation
To facilitate reading runtime and power consumption, we have class Stamp to take both measurements. A stamp object is created at the beginning and end of readings. In this case it is done before and after the algorithms are run. When the objects are created, they store the current clock time using std::chrono and power consumption using the RAPL library. Member functions are used to return the time or power difference between two Stamp objects. 

All of the sorting algorithms analyzed are accessed from an array of function pointers. We iterate through each function and use it to sort an array of data. After each iteration of sorting the array, a larger array is used to gather data for larger values of N. We use the stamp class to measure the time and power consumption before and after the sorting. We can then graph the difference for each algorithm at different values of array size N.

All of this is done in a function <code>measureFunctionPerformance()</code>, which takes a list of function pointers, a list of function names (parallel at index to the function pointers), and and array of sizes to iterate through, testing each sorting algorithm per size. It generates the arrays to sort, performs a time/energy stamp before and after each sorting algorithm is called, and outputs results to the data file.

All output is redirected to one .data file, which we parse and graphs with a Python script using matplotlib.

## Graphing results
Our graphs show the expected results. Bubble sort and insertion sort have quadratic performance. Merge sort, Merge sort optimized, Quick sort and Heap sort, all have logarithmic performance. Bogosort is...surprisingly acceptable for sizes of N less than 6, but quickly spirals out of proportion, as we stopped gathering data for sizes of N larger than 12.

There is a clear correlation between run time and energy consumption. This is to be expected, and there are no unexpected differences between the metrics. The run time and energy consumption graphs grow at the same time.
We have used the python script to plot the results after writing the readings to a text file.

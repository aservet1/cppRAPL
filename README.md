# Time and Energy Analysis of Sorting Algorithms

This application measures the runtime and power consumption of sorting algorithms in C++

## Sorting algorithms analyzed
@TODO MAKE SURE THSE ARE THE SORTS WE ARE ACTUALLY USING
+ Bubble Sort
+ Insertion Sort
+ Merge Sort
+ Merge Sort Optimized
+ Quicksort
+ Quicksort Optimized
+ Counting Sort
+ Bogosort

## How are we measuring power consumption?
The RAPL library, implemented in C, is adapted from an independent research project, [jRAPL](https://github.com/aservet1/jRAPL), that Rutvik and Alejandro are working on for Professor Yu David Liu. @TODO: link to the jRAPL repo

RAPL stands for Running Average Power Limit, a way of monitoring and controlling a computer's energy levels. It works on Intel processors by reading and writing the Model Specific Registers (MSRs). In this project, we only directly access one function from the library, EnergyStatCheck(), which returns total energy consumption. We call the function before and after running our sorting algorithms and take the difference in readings.
EnergyStatCheck() returns energy readings for three different power domains: DRAM, CPU, and Package. Package is the entire CPU socket. Our algorithms will therefore be measured with respect to energy consumption in each of these three power domains.
   ##### System requirements
   The energy reading utility currently only works for Intel processors on Linux systems. Root access required

## How are we measuring runtime?
Using std::chrono we can timestamp before and after a function runs and take the difference to measure the elapsed time.
To facilitate reading runtime and power consumption, we have class Stamp to take both measurements. A stamp object is created at the beggining and end of readings. In this case it is done before and after the algorithms are run. When the objects are created, they store the current clock time using std::chrono and power consumption using the RAPL library. Member functions are used to return the time or power difference between two Stamp objects.

## Performance analysis implementation
Our sorting algorithms are accessed in an array of function pointers. We iterate through pass each algorithm into a performance analysis function @TODO what's it called?
The performance analysis function ........

## Graphing results

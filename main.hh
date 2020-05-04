#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include "algorithms/mergeSort.hh"
#include "algorithms/heapSort.hh"
#include "algorithms/quickSort.hh"
#include "algorithms/sorts.hh"


extern "C"
{
	#include "RAPL-Library/CPUScaler_noJNI.h"
}

using namespace std;

//stod, atof, etc. are not precise, but we need every decimal point provided in the string
//assume "xxxxx.xxxxx" string passed in


struct EnergyArrays{
	int n;
	double *dram;
	double *package;
	double *core;
	EnergyArrays(int n): n(n){
		dram = new double[n];
		package = new double[n];
		core = new double[n];
	}
	~EnergyArrays(){
		delete[] dram;
		delete[] package;
		delete[] core;
	}

	void printArrays(){
		for(int i = 0; i < n; i++){
			std::cout << setprecision(20) << "DRAM: " << dram[i] << "  PACKAGE: " << package[i] << "  CORE: " << core[i] << std::endl;
		}
	}
};

// Split by delimiter, pass by valuse because it destroys the string
static vector<string> split(string line, char delim)
{
	vector<string> result;
	while (line.length() != 0)
	{
		string token;
		if (line.find(delim) == string::npos)
		{
			token = line;
			line.erase(0, line.length());
		}
		else
		{
			token = line.substr(0, line.find(delim));
			line.erase(0, line.find(delim)+1);
		}
		result.push_back(token);
	}
	return result;
}


/**	The C side function EnergyStatCheck() mallocs a char*,
	so this function frees it and returns an array of the info

	first entry is dram power
	second entry is core power
	third entry is package power (entire cpu socket, assuming only 1 socket)
*/
static vector<double>
getEnergyReadings()
{
	char* energy_stat_check = EnergyStatCheck();
	string ener_info_string(energy_stat_check);
	free(energy_stat_check);
	vector<string> ener_info_split = split(ener_info_string, '#');
	
	vector<double> ener_info;	
	for (string info : ener_info_split)
	{
		ener_info.push_back(stod(info));
	}
	return ener_info;
}

EnergyArrays* getEnergySamples(int iter, int delay)
{
	EnergyArrays *e = new EnergyArrays(iter);
	srand(rand());
	for (int i = 0; i < iter; i++)
	{
		vector<double> before = getEnergyReadings();
		this_thread::sleep_for(chrono::milliseconds(delay * (rand() % 3 + 1)));
		vector<double> after  = getEnergyReadings();
		e->dram[i] = after[0] - before[0];
		e->core[i]  = after[1] - before[1];
		e->package[i]  = after[2] - before[2];
	}
	return e;
}


struct stamp{
	vector<double> energy;
	
};



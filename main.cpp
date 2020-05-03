#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
//#include <boost/algorithm/string.hpp>

extern "C"
{
	#include "RAPL-Library/CPUScaler_noJNI.h"
}

using namespace std;

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
	cout << ener_info_string << endl;
	vector<string> ener_info_split = split(ener_info_string, '#');
	vector<double> ener_info;
	for (string info : ener_info_split)
	{
		double d = atof(info.c_str());
		//cout << info << "/" << d << endl;
		ener_info.push_back(d);
	}
	return ener_info;
}

void printEnergySamples(int iter, int delay)
{
	for (int i = 0; i < iter; i++)
	{
		vector<double> before = getEnergyReadings();
		this_thread::sleep_for(chrono::seconds(delay));
		vector<double> after  = getEnergyReadings();
		int dram = before[0] - after[0];
		int cpu  = before[1] - after[1];
		int pkg  = before[2] - after[2];
		cout << "dram:\t" << dram << "\tcpu:\t" << cpu << "\tpkg:\t" << pkg << endl;
	}
}

int main(int argc, char *argv[])
{
	ProfileInit();
	printEnergySamples(10,1);
	ProfileDealloc();
	return 0;
};

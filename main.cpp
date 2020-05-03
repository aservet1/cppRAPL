#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
//#include <boost/algorithm/string.hpp>
#include <cmath>
#include <iomanip>

extern "C"
{
	#include "RAPL-Library/CPUScaler_noJNI.h"
}

using namespace std;

//stod, atof, etc. are not precise, but we need every decimal point provided in the string
//assume "xxxxx.xxxxx" string passed in
static long double precise_stod(string str)
{
	int num_pre_radixpt = str.find(".");
	int num_post_radixpt;
	if (num_pre_radixpt == -1) 
	{
		num_pre_radixpt = str.size();
		num_post_radixpt = 0;
	}
	else
	{ 
		num_post_radixpt = str.size()-1-num_pre_radixpt;
	}
	//cout << num_pre_radixpt << " / " << num_post_radixpt << endl;

	int power = num_pre_radixpt-1;
	long double multiplier = pow(10,power);
	long double result = 0;
	
	int i = 0;
	while(str[i] != '.')
	{
		long double added = (str[i]-'0') * multiplier;
		cout << "added: " << added << endl;
		result += added;
		power--;
		multiplier = pow(10, power);
		//cout << "1multiplier: " << multiplier << endl;
		i++;
	}	

	i++;
	power = 1;
	multiplier = .1;

	while(i < str.size())
	{
		long double added = (str[i]-'0') * multiplier; 
		cout << "added: " << added << endl;
		result += added;
		power++;
		multiplier = 1 / pow(10, power);
		//cout << "2multiplier: " << multiplier << endl;
		i++;
	}

	/*for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '.') continue;
		result += (str[i]-'0') * multiplier;
		power--;
		multiplier = pow(10,power);
	}*/

	return result;
}

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
	//cout << ener_info_string << endl;
	vector<string> ener_info_split = split(ener_info_string, '#');
	vector<double> ener_info;
	for (string info : ener_info_split)
	{
		//char end = '\0';
		//char* pend = &end;
		//float d = strtof(info.c_str(),&pend);
		//cout << info << "/" << d << endl;
		ener_info.push_back(stod(info));
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
		double dram = after[0] - before[0];
		double cpu  = after[1] - before[1];
		double pkg  = after[2] - before[2];
		cout << "dram:\t" << setprecision(20) << dram << "\tcpu:\t" << setprecision(20) << cpu << "\tpkg:\t" << setprecision(20) << pkg << endl;
	}
}

int main(int argc, char *argv[])
{
//	cout << setprecision(16) << atof(argv[1]) << endl;

	ProfileInit();
	printEnergySamples(10,10);
	ProfileDealloc();
	return 0;
};

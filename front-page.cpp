#include <iostream>
#include <vector>

extern "C"
{
	#include "RAPL-Library/CPUScaler_noJNI.h"
}



using namespace std;


static string
getEnergyStatString()
{
	char* rapl_energy_info = EnergyStatCheck();
	printf("%s\n",rapl_energy_info);
	string rapl_energy_info_string(rapl_energy_info);
	free(rapl_energy_info);
	return rapl_energy_info_string;
}

int main(int argc, char *argv[])
{
	ProfileInit();
	cout << getEnergyStatString() << endl;
	ProfileDealloc();
	return 0;
};

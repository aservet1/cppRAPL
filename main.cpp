#include <iostream>
#include <vector>

extern "C"
{
	#include "RAPL-Library/CPUScaler_noJNI.h"
}

using namespace std;

/**	The C side function mallocs a char*, so this function turns
	it into an std::string and frees the C program's .alloc
*/
static string
getEnergyStatString()
{
	char* rapl_energy_info = EnergyStatCheck();
	string rapl_energy_info_string(rapl_energy_info);
	free(rapl_energy_info); //@TODO -- this doesn't actually free
	return rapl_energy_info_string;
}

int main(int argc, char *argv[])
{
	ProfileInit();
	cout << getEnergyStatString() << endl;
	ProfileDealloc();
	return 0;
};

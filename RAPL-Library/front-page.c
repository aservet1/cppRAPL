#include <stdio.h>
#include <stdlib.h>

#include "CPUScaler_noJNI.h"

void
getEnergyStats()
{
	char* rapl_energy_info = EnergyStatCheck();
	printf("%s\n",rapl_energy_info);	
	free(rapl_energy_info);
}

int main(int argc, char *argv[])
{
	ProfileInit();
	getEnergyStats();
	ProfileDealloc();
	return 0;
};

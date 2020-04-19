#ifndef CPUSCALER_noJNI_H
#define CPUSCALER_noJNI_H


#include "arch_spec_noJNI.h"
#include "msr_noJNI.h"

//static rapl_msr_parameter *parameters;
//static int *fd;
static uint64_t num_pkg;

void copy_to_string(char *ener_info, char uncore_buffer[60], int uncore_num, char cpu_buffer[60], int cpu_num, char package_buffer[60], int package_num, int i, int *offset);

rapl_msr_unit get_rapl_unit();

int ProfileInit();

int GetSocketNum();

void initialize_energy_info(char gpu_buffer[num_pkg][60], char dram_buffer[num_pkg][60], char cpu_buffer[num_pkg][60], char package_buffer[num_pkg][60]);

char* EnergyStatCheck();

void ProfileDealloc();

#endif //CPUSCALER_H

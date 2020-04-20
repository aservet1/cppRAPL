#include<stdio.h>
#include "arch_spec_noJNI.h"


int main()
{
	uint32_t cpu_model = get_cpu_model();
	printf("cpu model is: %X\n",cpu_model);

	int dram_or_gpu = get_architecture_category(cpu_model);
	switch (dram_or_gpu) {
		case READ_FROM_DRAM:
			printf("reads from dram buffer\n");
			break;
		case READ_FROM_GPU:
			printf("reads from gpu buffer\n");
			break;
		default:
			printf("undefined architecture!!");
	}

	return 0;
}

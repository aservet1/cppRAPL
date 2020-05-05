#ifndef ENERGY_READINGS_HH
#define ENERGY_READINGS_HH

#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include "helperFunctions.hh"

extern "C" {
  #include "RAPL-Library/CPUScaler_noJNI.h"
}

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
      std::cout << std::setprecision(20) << "DRAM: " << dram[i] << "  PACKAGE: " << package[i] << "  CORE: " << core[i] << std::endl;
    }
  }
};


// Returns a vector of [total_dram_power, toal_core_power, total_package_power]
static std::vector<double>
getEnergyReadings(){
  char* energy_stat_check = EnergyStatCheck();
  std::string ener_info_string(energy_stat_check);
  free(energy_stat_check);
  std::vector<std::string> ener_info_split = split(ener_info_string, '#');

  std::vector<double> ener_info;	
  for (std::string info : ener_info_split){
    ener_info.push_back(stod(info));
  }
  return ener_info;
}

EnergyArrays* getEnergySamples(int iter, int delay){
  EnergyArrays *e = new EnergyArrays(iter);
  srand(rand());
  for (int i = 0; i < iter; i++){
    std::vector<double> before = getEnergyReadings();
    std::this_thread::sleep_for(std::chrono::milliseconds(delay * (rand() % 3 + 1)));
    std::vector<double> after  = getEnergyReadings();
    e->dram[i] = after[0] - before[0];
    e->core[i]  = after[1] - before[1];
    e->package[i]  = after[2] - before[2];
  }
  return e;
}

#endif

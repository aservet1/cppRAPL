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

struct EnergyArray{
  int n;
  double *core;
  EnergyArray(int n): n(n){
    core = new double[n];
  }
  ~EnergyArray(){
    delete[] core;
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

EnergyArray* getEnergySamples(int iter, int delay){
  EnergyArray *e = new EnergyArray(iter);
  srand(rand());
  for (int i = 0; i < iter; i++){
    std::vector<double> before = getEnergyReadings();
    std::this_thread::sleep_for(std::chrono::milliseconds(delay * (rand() % 3 + 1)));
    std::vector<double> after  = getEnergyReadings();
    e->core[i]  = after[1] - before[1];
  }
  return e;
}

#endif

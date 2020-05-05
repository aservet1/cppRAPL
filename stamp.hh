#ifndef STAMP_HH
#define STAMP_HH

#include <chrono>
#include "energyReadings.hh"

class Stamp{
  public:
  std::chrono::steady_clock::time_point time;
  std::vector<double> energy;

  Stamp(){
    time = std::chrono::steady_clock::now();
    energy = getEnergyReadings();
  }

  ~Stamp(){ }

  Stamp(const Stamp &old){
    time = old.time;
    energy = old.energy;
  }

  int
  timeDifference(Stamp start){
    return std::chrono::duration_cast<std::chrono::nanoseconds>(time - start.time).count();	 
  }
	
  std::vector<double>
  energyDifference(Stamp start){
    auto i1 = start.energy.cbegin();
    auto i2 = energy.cbegin();
    std::vector<double> energy_difference;
    for(; (i1 != start.energy.cend()) && (i2 != energy.cend()) ; i1++, i2++ ){
      double difference = *i2 - *i1;
      energy_difference.push_back(difference);
    }
    return energy_difference;
  }
};

#endif

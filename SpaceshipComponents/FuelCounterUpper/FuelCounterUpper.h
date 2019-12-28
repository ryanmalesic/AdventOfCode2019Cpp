//
// Created by Ryan Malesic on 12/19/19.
//

#ifndef ADVENTOFCODE2019_C___FUELCOUNTERUPPER_H
#define ADVENTOFCODE2019_C___FUELCOUNTERUPPER_H

#include <vector>

typedef int module_t;
typedef std::vector<int> modules_t;

class FuelCounterUpper {
 public:
  explicit FuelCounterUpper(modules_t modules);

  int calculateFuelRequirements();
  int calculateTotalFuelRequirements();

 private:
  modules_t modules;

  int calculateTotalFuelRequirementForModule(const module_t &module);
};

#endif  // ADVENTOFCODE2019_C___FUELCOUNTERUPPER_H

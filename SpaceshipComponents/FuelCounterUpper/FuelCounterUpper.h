//
// Created by Ryan Malesic on 12/19/19.
//

#ifndef ADVENTOFCODE2019_C___FUELCOUNTERUPPER_H
#define ADVENTOFCODE2019_C___FUELCOUNTERUPPER_H

#include <vector>

class FuelCounterUpper {
 public:
  explicit FuelCounterUpper(std::vector<int> modules);

  int calculateFuelRequirements();
  int calculateTotalFuelRequirements();

 private:
  std::vector<int> modules;

  int calculateTotalFuelRequirementForModule(const int &module);
};

#endif  // ADVENTOFCODE2019_C___FUELCOUNTERUPPER_H

//
// Created by Ryan Malesic on 12/19/19.
//

#include "FuelCounterUpper.h"

#include <numeric>

FuelCounterUpper::FuelCounterUpper(modules_t modules)
    : modules(std::move(modules)) {}

int FuelCounterUpper::calculateFuelRequirements() {
  return std::transform_reduce(
      this->modules.begin(), this->modules.end(), 0,
      [](const int &a, const int &b) { return a + b; },
      [](const int &m) { return m / 3 - 2; });
}

int FuelCounterUpper::calculateTotalFuelRequirements() {
  return std::transform_reduce(
      this->modules.begin(), this->modules.end(), 0,
      [](const int &a, const int &b) { return a + b; },
      [this](const int &m) {
        return this->calculateTotalFuelRequirementForModule(m / 3 - 2);
      });
}

int FuelCounterUpper::calculateTotalFuelRequirementForModule(
    const module_t &module) {
  if (module <= 0) {
    return 0;
  }

  return module + this->calculateTotalFuelRequirementForModule(module / 3 - 2);
}

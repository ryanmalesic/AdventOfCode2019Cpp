//
// Created by Ryan Malesic on 12/19/19.
//

#include "Day1.h"

#include <fstream>

#include "../../SpaceshipComponents/FuelCounterUpper/FuelCounterUpper.h"

Day1::Day1(const std::string& inputFile) : Day(inputFile) {
  modules_t parsedInput;

  std::ifstream inputStream(inputFile);
  std::string inputString;
  const char delim = '\n';

  while (getline(inputStream, inputString, delim)) {
    parsedInput.push_back(stoi(inputString));
  }

  this->parsedInput = parsedInput;
}

int Day1::part1() {
  FuelCounterUpper fcu(this->parsedInput);
  return fcu.calculateFuelRequirements();
}

int Day1::part2() {
  FuelCounterUpper fcu(this->parsedInput);
  return fcu.calculateTotalFuelRequirements();
}
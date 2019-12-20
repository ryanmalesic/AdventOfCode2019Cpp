//
// Created by Ryan Malesic on 12/19/19.
//

#include "Day1.h"

#include <fstream>
#include <string>
#include <vector>

#include "../../SpaceshipComponents/FuelCounterUpper/FuelCounterUpper.h"

void Day1::parse(std::string inputFile) {
  std::vector<int> input;

  std::ifstream inputStream(inputFile);
  std::string inputString;
  const char delim = '\n';

  while (getline(inputStream, inputString, delim)) {
    input.push_back(stoi(inputString));
  }

  this->input = input;
}

int Day1::part1() {
  this->parse(this->inputFile);
  FuelCounterUpper fcu(this->input);
  return fcu.calculateFuelRequirements();
}

int Day1::part2() {
  this->parse(this->inputFile);
  FuelCounterUpper fcu(this->input);
  return fcu.calculateTotalFuelRequirements();
}
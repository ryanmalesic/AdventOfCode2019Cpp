//
// Created by Ryan Malesic on 12/20/19.
//

#include "Day6.h"

#include <fstream>
#include <iostream>

#include "../../SpaceshipComponents/OrbitMap/OrbitMap.h"

Day6::Day6(const std::string& inputFile) : Day(inputFile) {
  orbits_t parsedInput;

  std::ifstream inputStream(inputFile);
  std::string inputString;
  const char delim = '\n';

  while (getline(inputStream, inputString, delim)) {
    parsedInput.push_back(inputString);
  }

  this->parsedInput = parsedInput;
}

int64_t Day6::part1() {
  OrbitMap orbitMap = OrbitMap(this->parsedInput);
  return orbitMap.getOrbitCountChecksum();
}

int64_t Day6::part2() {
  OrbitMap orbitMap = OrbitMap(this->parsedInput);
  return orbitMap.getMinStepsToSanta();
}
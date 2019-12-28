//
// Created by Ryan Malesic on 12/20/19.
//

#include "Day6.h"

#include <fstream>
#include <iostream>
#include <string>

#include "../../SpaceshipComponents/OrbitMap/OrbitMap.h"

void Day6::parse(std::string inputFile) {
  std::ifstream inputStream(inputFile);
  std::string inputString;
  const char delim = '\n';

  while (getline(inputStream, inputString, delim)) {
    this->input.push_back(inputString);
  }
}

int Day6::part1() {
  this->parse(this->inputFile);
  OrbitMap orbitMap = OrbitMap(this->input);
  return orbitMap.getOrbitCountChecksum();
}

int Day6::part2() {
  this->parse(this->inputFile);
  OrbitMap orbitMap = OrbitMap(this->input);
  return orbitMap.getMinStepsToSanta();
}
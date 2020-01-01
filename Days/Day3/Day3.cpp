//
// Created by Ryan Malesic on 12/19/19.
//

#include "Day3.h"

#include <fstream>
#include <sstream>

#include "../../SpaceshipComponents/FuelManagementSystem/FuelManagementSystem.h"

Day3::Day3(const std::string& inputFile) : Day(inputFile) {
  wires_t parsedInput;

  std::ifstream inputStream(inputFile);
  std::string line;

  size_t index = 0;
  while (getline(inputStream, line, '\n')) {
    std::stringstream elementStream(line);
    std::string element;
    while (getline(elementStream, element, ',')) {
      if (index == 0) {
        parsedInput.first.push_back(element);
      } else {
        parsedInput.second.push_back(element);
      }
    }
    ++index;
  }

  this->parsedInput = parsedInput;
}

int64_t Day3::part1() {
  FuelManagementSystem fuelManagementSystem(parsedInput);
  return fuelManagementSystem.getClosetIntersection();
}

int64_t Day3::part2() {
  FuelManagementSystem fuelManagementSystem(parsedInput);
  return fuelManagementSystem.getMinSteps();
}
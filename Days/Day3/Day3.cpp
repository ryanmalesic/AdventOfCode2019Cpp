//
// Created by Ryan Malesic on 12/19/19.
//

#include "Day3.h"

#include <fstream>
#include <sstream>
#include <string>

#include "../../SpaceshipComponents/FuelManagementSystem/FuelManagementSystem.h"

void Day3::parse(std::string inputFile) {
  std::ifstream inputStream(inputFile);
  std::string line;

  wires_t wires;

  size_t index = 0;
  while (getline(inputStream, line, '\n')) {
    std::stringstream elementStream(line);
    std::string element;
    while (getline(elementStream, element, ',')) {
      if (index == 0) {
        wires.first.push_back(element);
      } else {
        wires.second.push_back(element);
      }
    }
    ++index;
  }

  this->input = wires;
}

int Day3::part1() {
  this->parse(this->inputFile);
  FuelManagementSystem fuelManagementSystem(input);
  return fuelManagementSystem.getClosetIntersection();
}

int Day3::part2() {
  this->parse(this->inputFile);
  FuelManagementSystem fuelManagementSystem(input);
  return fuelManagementSystem.getMinSteps();
}
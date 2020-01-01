//
// Created by Ryan Malesic on 12/19/19.
//

#ifndef ADVENTOFCODE2019_C___DAY1_H
#define ADVENTOFCODE2019_C___DAY1_H

#include <string>
#include <vector>

#include "../../SpaceshipComponents/FuelCounterUpper/FuelCounterUpper.h"
#include "../Day/Day.h"

class Day1 : public Day {
 public:
  explicit Day1(const std::string& inputFile);

 private:
  modules_t parsedInput;

  int64_t part1() override;
  int64_t part2() override;
};

#endif  // ADVENTOFCODE2019_C___DAY1_H

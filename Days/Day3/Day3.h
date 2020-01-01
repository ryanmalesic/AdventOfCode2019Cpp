//
// Created by Ryan Malesic on 12/19/19.
//

#ifndef ADVENTOFCODE2019CPP_DAY3_H
#define ADVENTOFCODE2019CPP_DAY3_H

#include <string>
#include <vector>

#include "../../SpaceshipComponents/FuelManagementSystem/FuelManagementSystem.h"
#include "../Day/Day.h"

class Day3 : public Day {
 public:
  explicit Day3(const std::string& inputFile);

 private:
  wires_t parsedInput;

  int64_t part1() override;
  int64_t part2() override;
};

#endif  // ADVENTOFCODE2019CPP_DAY3_H

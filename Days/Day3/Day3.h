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
  using Day::Day;

 private:
  wires_t input;

  void parse(std::string inputFile) override;
  int part1() override;
  int part2() override;
};

#endif  // ADVENTOFCODE2019CPP_DAY3_H

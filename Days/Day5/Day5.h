//
// Created by Ryan Malesic on 12/20/19.
//

#ifndef ADVENTOFCODE2019CPP_DAY5_H
#define ADVENTOFCODE2019CPP_DAY5_H

#include <vector>

#include "../../SpaceshipComponents/IntCodeComputer/IntCodeComputer.h"
#include "../Day/Day.h"

class Day5 : public Day {
 public:
  explicit Day5(const std::string& inputFile);

 private:
  program_t parsedInput;

  int part1() override;
  int part2() override;
};

#endif  // ADVENTOFCODE2019CPP_DAY5_H

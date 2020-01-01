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

  int64_t part1() override;
  int64_t part2() override;
};

#endif  // ADVENTOFCODE2019CPP_DAY5_H

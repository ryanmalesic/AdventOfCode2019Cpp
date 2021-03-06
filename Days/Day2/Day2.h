//
// Created by Ryan Malesic on 12/19/19.
//

#ifndef ADVENTOFCODE2019CPP_DAY2_H
#define ADVENTOFCODE2019CPP_DAY2_H

#include <vector>

#include "../../SpaceshipComponents/IntCodeComputer/IntCodeComputer.h"
#include "../Day/Day.h"

class Day2 : public Day {
 public:
  explicit Day2(const std::string& inputFile);

 private:
  program_t parsedInput;

  int64_t part1() override;
  int64_t part2() override;
};

#endif  // ADVENTOFCODE2019CPP_DAY2_H

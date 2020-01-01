//
// Created by Ryan Malesic on 1/1/20.
//

#ifndef ADVENTOFCODE2019CPP_DAY9_H
#define ADVENTOFCODE2019CPP_DAY9_H

#include <vector>

#include "../../SpaceshipComponents/IntCodeComputer/IntCodeComputer.h"
#include "../Day/Day.h"

class Day9 : public Day {
 public:
  explicit Day9(const std::string& inputFile);

 private:
  program_t parsedInput;

  int64_t part1() override;
  int64_t part2() override;
};

#endif  // ADVENTOFCODE2019CPP_DAY9_H

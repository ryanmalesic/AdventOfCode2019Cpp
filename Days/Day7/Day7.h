//
// Created by Ryan Malesic on 12/28/19.
//

#ifndef ADVENTOFCODE2019CPP_DAY7_H
#define ADVENTOFCODE2019CPP_DAY7_H

#include <string>

#include "../../SpaceshipComponents/IntCodeComputer/IntCodeComputer.h"
#include "../Day/Day.h"

class Day7 : public Day {
 public:
  explicit Day7(const std::string& inputFile);

 private:
  program_t parsedInput;

  int part1() override;
  int part2() override;
};

#endif  // ADVENTOFCODE2019CPP_DAY7_H

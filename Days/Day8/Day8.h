//
// Created by Ryan Malesic on 12/29/19.
//

#ifndef ADVENTOFCODE2019CPP_DAY8_H
#define ADVENTOFCODE2019CPP_DAY8_H

#include <string>
#include <vector>

#include "../Day/Day.h"

class Day8 : public Day {
 public:
  explicit Day8(const std::string& inputFile);

 private:
  std::vector<int> parsedInput;
  int part1() override;
  int part2() override;
};

#endif  // ADVENTOFCODE2019CPP_DAY8_H

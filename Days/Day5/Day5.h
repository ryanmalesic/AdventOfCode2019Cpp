//
// Created by Ryan Malesic on 12/20/19.
//

#ifndef ADVENTOFCODE2019CPP_DAY5_H
#define ADVENTOFCODE2019CPP_DAY5_H

#include <vector>

#include "../Day/Day.h"

class Day5 : public Day {
 public:
  explicit Day5(const std::string& inputFile);

 private:
  std::vector<int64_t> parsedInput;

  int part1() override;
  int part2() override;
};

#endif  // ADVENTOFCODE2019CPP_DAY5_H

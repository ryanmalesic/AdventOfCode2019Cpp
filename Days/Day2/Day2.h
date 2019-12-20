//
// Created by Ryan Malesic on 12/19/19.
//

#ifndef ADVENTOFCODE2019CPP_DAY2_H
#define ADVENTOFCODE2019CPP_DAY2_H

#include <vector>

#include "../Day/Day.h"

class Day2 : public Day {
 public:
  using Day::Day;

 private:
  std::vector<int64_t> input;

  void parse(std::string inputFile) override;
  int part1() override;
  int part2() override;
};

#endif  // ADVENTOFCODE2019CPP_DAY2_H

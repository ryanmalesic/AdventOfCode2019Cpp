//
// Created by Ryan Malesic on 12/20/19.
//

#ifndef ADVENTOFCODE2019CPP_DAY5_H
#define ADVENTOFCODE2019CPP_DAY5_H

#include <vector>

#include "../Day/Day.h"

class Day5 : public Day {
 public:
  using Day::Day;

 private:
  std::vector<int64_t> input;

  void parse(std::string inputFile) override;
  int part1() override;
  int part2() override;
};

#endif  // ADVENTOFCODE2019CPP_DAY5_H

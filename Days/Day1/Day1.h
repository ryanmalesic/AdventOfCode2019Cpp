//
// Created by Ryan Malesic on 12/19/19.
//

#ifndef ADVENTOFCODE2019_C___DAY1_H
#define ADVENTOFCODE2019_C___DAY1_H

#include <string>
#include <vector>

#include "../Day/Day.h"

class Day1 : public Day {
 public:
  using Day::Day;

 private:
  std::vector<int> input;

  void parse(std::string inputFile) override;
  int part1() override;
  int part2() override;
};

#endif  // ADVENTOFCODE2019_C___DAY1_H

//
// Created by Ryan Malesic on 12/20/19.
//

#ifndef ADVENTOFCODE2019CPP_DAY4_H
#define ADVENTOFCODE2019CPP_DAY4_H

#include <string>

#include "../Day/Day.h"

class Day4 : public Day {
 public:
  explicit Day4(const std::string& inputFile);
  ~Day4();

 private:
  int* parsedInput;

  int part1() override;
  int part2() override;

  static bool isAscending(const int&);
  static bool hasTwoInARow(const int&);
  static bool hasOnlyTwoInARow(const int&);
};

#endif  // ADVENTOFCODE2019CPP_DAY4_H

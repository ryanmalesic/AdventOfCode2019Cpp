//
// Created by Ryan Malesic on 12/19/19.
//

#ifndef ADVENTOFCODE2019CPP_DAY_H
#define ADVENTOFCODE2019CPP_DAY_H

#include <string>
#include <variant>

class Day {
 public:
  explicit Day(std::string inputFile);

  std::variant<int, std::pair<int, int>> solve(bool part1, bool part2);

 private:
  virtual int part1() = 0;
  virtual int part2() = 0;

 protected:
  std::string inputFile;
};

#endif  // ADVENTOFCODE2019CPP_DAY_H

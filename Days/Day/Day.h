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

  std::variant<int64_t, std::pair<int64_t, int64_t>> solve(bool part1,
                                                           bool part2);

 private:
  virtual int64_t part1() = 0;
  virtual int64_t part2() = 0;

 protected:
  std::string inputFile;
};

#endif  // ADVENTOFCODE2019CPP_DAY_H

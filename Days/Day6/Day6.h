//
// Created by Ryan Malesic on 12/20/19.
//

#ifndef ADVENTOFCODE2019CPP_DAY6_H
#define ADVENTOFCODE2019CPP_DAY6_H

#include <string>
#include <vector>

#include "../../SpaceshipComponents/OrbitMap/OrbitMap.h"
#include "../Day/Day.h"

class Day6 : public Day {
 public:
  explicit Day6(const std::string& inputFile);

 private:
  orbits_t parsedInput;

  int64_t part1() override;
  int64_t part2() override;
};

#endif  // ADVENTOFCODE2019CPP_DAY6_H

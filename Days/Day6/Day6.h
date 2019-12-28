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
  using Day::Day;

 private:
  orbits_t input;

  void parse(std::string inputFile) override;
  int part1() override;
  int part2() override;
};

#endif  // ADVENTOFCODE2019CPP_DAY6_H

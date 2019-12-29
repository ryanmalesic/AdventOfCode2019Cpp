//
// Created by Ryan Malesic on 12/28/19.
//

#ifndef ADVENTOFCODE2019CPP_AMPLIFICATIONCIRCUIT_H
#define ADVENTOFCODE2019CPP_AMPLIFICATIONCIRCUIT_H

#include <vector>

#include "../IntCodeComputer/IntCodeComputer.h"

class AmplificationCircuit {
 public:
  explicit AmplificationCircuit(program_t);

  int amplifyInSeries();
  int amplifyInLoop();

 private:
  program_t amplifierControllerSoftware;
};

#endif  // ADVENTOFCODE2019CPP_AMPLIFICATIONCIRCUIT_H

//
// Created by Ryan Malesic on 12/19/19.
//

#include "Day2.h"

#include <fstream>
#include <string>

#include "../../SpaceshipComponents/IntCodeComputer/IntCodeComputer.h"

Day2::Day2(const std::string& inputFile) : Day(inputFile) {
  program_t parsedInput;

  std::ifstream inputStream(inputFile);
  std::string inputString;
  const char delim = ',';

  while (getline(inputStream, inputString, delim)) {
    parsedInput.push_back(stoi(inputString));
  }

  this->parsedInput = parsedInput;
}

int64_t Day2::part1() {
  IntCodeComputer icc;
  return icc.useProgram(this->parsedInput)
      .replaceProgramData({{1, 12}, {2, 2}})
      .execute()
      .accessMemory(0);
}

int64_t Day2::part2() {
  for (int noun = 0; noun < 100; ++noun) {
    for (int verb = 0; verb < 100; ++verb) {
      IntCodeComputer icc;
      if (icc.useProgram(this->parsedInput)
              .replaceProgramData({{1, noun}, {2, verb}})
              .execute()
              .accessMemory(0) == 19690720) {
        return 100 * noun + verb;
      }
    }
  }
}
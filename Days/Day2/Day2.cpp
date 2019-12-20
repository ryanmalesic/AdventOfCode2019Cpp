//
// Created by Ryan Malesic on 12/19/19.
//

#include "Day2.h"

#include <fstream>
#include <string>
#include <vector>

#include "../../SpaceshipComponents/IntCodeComputer/IntCodeComputer.h"

void Day2::parse(std::string inputFile) {
  std::vector<int64_t> input;

  std::ifstream inputStream(inputFile);
  std::string inputString;
  const char delim = ',';

  while (getline(inputStream, inputString, delim)) {
    input.push_back(stoi(inputString));
  }

  this->input = input;
}

int Day2::part1() {
  this->parse(this->inputFile);
  IntCodeComputer icc;
  return icc.useProgram(this->input)
      .replaceProgramData({{1, 12}, {2, 2}})
      .execute()
      .accessMemory(0);
}

int Day2::part2() {
  this->parse(this->inputFile);

  for (int noun = 0; noun < 100; ++noun) {
    for (int verb = 0; verb < 100; ++verb) {
      IntCodeComputer icc;
      if (icc.useProgram(this->input)
              .replaceProgramData({{1, noun}, {2, verb}})
              .execute()
              .accessMemory(0) == 19690720) {
        return 100 * noun + verb;
      }
    }
  }
}
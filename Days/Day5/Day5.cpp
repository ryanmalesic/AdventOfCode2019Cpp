//
// Created by Ryan Malesic on 12/20/19.
//

#include "Day5.h"

#include <fstream>
#include <vector>

#include "../../SpaceshipComponents/IntCodeComputer/IntCodeComputer.h"

void Day5::parse(std::string inputFile) {
  std::vector<int64_t> input;

  std::ifstream inputStream(inputFile);
  std::string inputString;
  const char delim = ',';

  while (getline(inputStream, inputString, delim)) {
    input.push_back(stoi(inputString));
  }

  this->input = input;
}

int Day5::part1() {
  this->parse(this->inputFile);

  IntCodeComputer intCodeComputer;
  return intCodeComputer.useProgram(this->input)
      .input({1})
      .execute()
      .output()
      .back();
}

int Day5::part2() {
  this->parse(this->inputFile);

  IntCodeComputer intCodeComputer;
  return intCodeComputer.useProgram(this->input)
      .input({5})
      .execute()
      .output()
      .back();
}
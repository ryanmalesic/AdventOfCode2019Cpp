//
// Created by Ryan Malesic on 12/20/19.
//

#include "Day5.h"

#include <fstream>

Day5::Day5(const std::string& inputFile) : Day(inputFile) {
  std::vector<int64_t> parsedInput;

  std::ifstream inputStream(inputFile);
  std::string inputString;
  const char delim = ',';

  while (getline(inputStream, inputString, delim)) {
    parsedInput.push_back(stoi(inputString));
  }

  this->parsedInput = parsedInput;
}

int64_t Day5::part1() {
  IntCodeComputer intCodeComputer;
  return intCodeComputer.useProgram(this->parsedInput)
      .input({1})
      .execute()
      .output()
      .back();
}

int64_t Day5::part2() {
  IntCodeComputer intCodeComputer;
  return intCodeComputer.useProgram(this->parsedInput)
      .input({5})
      .execute()
      .output()
      .back();
}
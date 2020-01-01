//
// Created by Ryan Malesic on 1/1/20.
//

#include "Day9.h"

#include <fstream>
#include <iostream>

Day9::Day9(const std::string& inputFile) : Day(inputFile) {
  std::vector<int64_t> parsedInput;

  std::ifstream inputStream(inputFile);
  std::string inputString;
  const char delim = ',';

  while (getline(inputStream, inputString, delim)) {
    parsedInput.push_back(stoi(inputString));
  }

  this->parsedInput = parsedInput;
}

int64_t Day9::part1() {
  IntCodeComputer intCodeComputer;
  return intCodeComputer.useProgram(this->parsedInput)
      .input({1})
      .execute()
      .output()
      .back();
}

int64_t Day9::part2() {
  IntCodeComputer intCodeComputer;
  return intCodeComputer.useProgram(this->parsedInput)
      .input({2})
      .execute()
      .output()
      .back();
}
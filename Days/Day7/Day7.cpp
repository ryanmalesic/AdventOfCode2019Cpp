//
// Created by Ryan Malesic on 12/28/19.
//

#include "Day7.h"

#include <fstream>

#include "../../SpaceshipComponents/AmplificationCircuit/AmplificationCircuit.h"

Day7::Day7(const std::string& inputFile) : Day(inputFile) {
  std::vector<int64_t> parsedInput;

  std::ifstream inputStream(inputFile);
  std::string inputString;
  const char delim = ',';

  while (getline(inputStream, inputString, delim)) {
    parsedInput.push_back(stoi(inputString));
  }

  this->parsedInput = parsedInput;
}

int Day7::part1() {
  AmplificationCircuit amplificationCircuit(this->parsedInput);
  return amplificationCircuit.amplifyInSeries();
}

int Day7::part2() {
  AmplificationCircuit amplificationCircuit(this->parsedInput);
  return amplificationCircuit.amplifyInLoop();
}

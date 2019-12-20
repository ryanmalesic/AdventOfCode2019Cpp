//
// Created by Ryan Malesic on 12/19/19.
//

#ifndef ADVENTOFCODE2019CPP_INTCODECOMPUTER_H
#define ADVENTOFCODE2019CPP_INTCODECOMPUTER_H

#include <deque>
#include <unordered_map>
#include <vector>

enum intCodeComputerState {
  notExecuted,
  executing,
  waitingOnInput,
  terminated
};

class IntCodeComputer {
 public:
  IntCodeComputer();

  int64_t accessMemory(size_t);
  int64_t output();
  IntCodeComputer& execute();
  IntCodeComputer& input(const std::vector<int64_t>&);
  IntCodeComputer& replaceProgramData(
      const std::unordered_map<size_t, int64_t>&);
  IntCodeComputer& useProgram(std::vector<int64_t> program);

 private:
  std::vector<int64_t> program;
  size_t instructionPointer;
  size_t relativeBasePointer;
  std::deque<int64_t> inStream;
  std::deque<int64_t> outStream;
  intCodeComputerState state;

  int64_t** getArgs(int);
};

#endif  // ADVENTOFCODE2019CPP_INTCODECOMPUTER_H

//
// Created by Ryan Malesic on 12/19/19.
//

#ifndef ADVENTOFCODE2019CPP_INTCODECOMPUTER_H
#define ADVENTOFCODE2019CPP_INTCODECOMPUTER_H

#include <deque>
#include <unordered_map>
#include <vector>

typedef int64_t memory_t;
typedef std::vector<int64_t> program_t;
typedef std::deque<int64_t> stream_t;

enum intCodeComputerState {
  notExecuted,
  executing,
  waitingOnInput,
  terminated
};

class IntCodeComputer {
 public:
  IntCodeComputer();

  memory_t accessMemory(size_t);
  stream_t output();
  IntCodeComputer& execute();
  IntCodeComputer& input(const program_t&);
  IntCodeComputer& replaceProgramData(
      const std::unordered_map<size_t, int64_t>&);
  IntCodeComputer& useProgram(program_t program);
  intCodeComputerState getState();

 private:
  program_t program;
  size_t instructionPointer;
  size_t relativeBasePointer;
  stream_t inStream;
  stream_t outStream;
  intCodeComputerState state;

  int64_t** getArgs(int);
};

#endif  // ADVENTOFCODE2019CPP_INTCODECOMPUTER_H

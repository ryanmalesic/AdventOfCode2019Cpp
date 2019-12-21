//
// Created by Ryan Malesic on 12/19/19.
//

#include "IntCodeComputer.h"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>

IntCodeComputer::IntCodeComputer()
    : program({}),
      instructionPointer(0),
      relativeBasePointer(0),
      inStream({}),
      outStream({}),
      state(notExecuted) {}

int64_t IntCodeComputer::accessMemory(size_t index) {
  return this->program[index];
}

std::deque<int64_t> IntCodeComputer::output() { return this->outStream; }

IntCodeComputer &IntCodeComputer::execute() {
  this->state = executing;

  int64_t opCode;
  int64_t **args;

  while (this->state == executing) {
    opCode = this->program[this->instructionPointer] % 100;

    switch (opCode) {
      case 1:
        args = this->getArgs(3);
        *args[2] = *args[0] + *args[1];
        this->instructionPointer += 4;
        delete[] args;
        break;
      case 2:
        args = this->getArgs(3);
        *args[2] = *args[0] * *args[1];
        this->instructionPointer += 4;
        delete[] args;
        break;
      case 3:
        if (this->inStream.empty()) {
          this->state = waitingOnInput;
          return *this;
        }

        args = this->getArgs(1);
        *args[0] = this->inStream.front();
        this->inStream.pop_front();
        this->instructionPointer += 2;
        delete[] args;
        break;
      case 4:
        args = this->getArgs(1);
        this->outStream.push_back(*args[0]);
        this->instructionPointer += 2;
        delete[] args;
        break;
      case 5:
        args = this->getArgs(2);
        if (*args[0] != 0) {
          this->instructionPointer = *args[1];
        } else {
          this->instructionPointer += 3;
        }
        delete[] args;
        break;
      case 6:
        args = this->getArgs(2);
        if (*args[0] == 0) {
          this->instructionPointer = *args[1];
        } else {
          this->instructionPointer += 3;
        }
        delete[] args;
        break;
      case 7:
        args = this->getArgs(3);
        *args[2] = (*args[0] < *args[1]) ? 1 : 0;
        this->instructionPointer += 4;
        delete[] args;
        break;
      case 8:
        args = this->getArgs(3);
        *args[2] = (*args[0] == *args[1]) ? 1 : 0;
        this->instructionPointer += 4;
        delete[] args;
        break;
      case 9:
        args = this->getArgs(1);
        this->relativeBasePointer += *args[0];
        this->instructionPointer += 2;
        delete[] args;
        break;
      case 99:
        this->state = terminated;
        break;
      default:
        break;
    }
  }

  return *this;
}

IntCodeComputer &IntCodeComputer::input(
    const std::vector<int64_t> &inputValues) {
  for (const int64_t &inputValue : inputValues) {
    this->inStream.push_back(inputValue);
  }

  return *this;
}

IntCodeComputer &IntCodeComputer::replaceProgramData(
    const std::unordered_map<size_t, int64_t> &indexToValuesMap) {
  for (const auto &pair : indexToValuesMap) {
    this->program[pair.first] = pair.second;
  }

  return *this;
}

IntCodeComputer &IntCodeComputer::useProgram(std::vector<int64_t> program) {
  this->program = std::move(program);

  return *this;
}

int64_t **IntCodeComputer::getArgs(int numberOfArgs) {
  auto **args = new int64_t *[numberOfArgs];
  auto *argValues = new int64_t[numberOfArgs];

  for (size_t i = 0; i < numberOfArgs; ++i) {
    argValues[i] = this->program[this->instructionPointer + i + 1];
  }

  int64_t modes = this->program[this->instructionPointer] / 100;

  for (int i = 0; i < numberOfArgs; ++i) {
    int64_t argMode = (modes / (int)pow(10, i)) % 10;

    if (argMode == 0) {
      args[i] = &this->program[argValues[i]];
    } else if (argMode == 1) {
      args[i] = &(argValues[i]);
    } else {
      args[i] = &(this->program[argValues[i] + this->relativeBasePointer]);
    }
  }

  return args;
}
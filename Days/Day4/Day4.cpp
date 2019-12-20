//
// Created by Ryan Malesic on 12/20/19.
//

#include "Day4.h"

#include <fstream>
#include <iostream>
#include <string>

void Day4::parse(std::string inputFile) {
  std::ifstream inputStream(inputFile);
  std::string inputString;
  const char delim = '-';

  size_t index = 0;
  while (getline(inputStream, inputString, delim)) {
    this->input[index] = (stoi(inputString));
    ++index;
  }
}

int Day4::part1() {
  this->parse(this->inputFile);
  int count = 0;

  for (int i = this->input[0]; i <= this->input[1]; ++i) {
    if (isAscending(i) && hasTwoInARow(i)) {
      ++count;
    }
  }

  return count;
}

int Day4::part2() {
  this->parse(this->inputFile);
  int count = 0;

  for (int i = this->input[0]; i <= this->input[1]; ++i) {
    if (isAscending(i) && hasOnlyTwoInARow(i)) {
      ++count;
    }
  }

  return count;
}

bool Day4::isAscending(const int& num) {
  std::string numStr = std::to_string(num);

  for (int i = 0; i < numStr.size() - 1; ++i) {
    if (numStr[i] > numStr[i + 1]) {
      return false;
    }
  }

  return true;
}

bool Day4::hasTwoInARow(const int& num) {
  std::string numStr = std::to_string(num);

  for (int i = 0; i < numStr.size() - 1; ++i) {
    if (numStr[i] == numStr[i + 1]) {
      return true;
    }
  }

  return false;
}

bool Day4::hasOnlyTwoInARow(const int& num) {
  std::string numStr = std::to_string(num);
  char previous = numStr[0];
  int count = 1;

  for (int i = 1; i < numStr.size(); ++i) {
    if (numStr[i] == previous) {
      ++count;
    } else {
      if (count == 2) {
        return true;
      }

      previous = numStr[i];
      count = 1;
    }
  }

  return count == 2;
}

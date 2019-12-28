//
// Created by Ryan Malesic on 12/19/19.
//

#include "Day.h"

Day::Day(std::string inputFile) : inputFile(std::move(inputFile)) {}

std::variant<int, std::pair<int, int>> Day::solve(bool part1, bool part2) {
  std::variant<int, std::pair<int, int>> solution;

  if (part1 == part2) {
    solution = std::pair<int, int>{this->part1(), this->part2()};
  } else if (part1) {
    solution = this->part1();
  } else if (part2) {
    solution = this->part2();
  }

  return solution;
}
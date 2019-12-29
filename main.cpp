#include <getopt.h>

#include <iostream>

#include "Days/Day1/Day1.h"
#include "Days/Day2/Day2.h"
#include "Days/Day3/Day3.h"
#include "Days/Day4/Day4.h"
#include "Days/Day5/Day5.h"
#include "Days/Day6/Day6.h"
#include "Days/Day7/Day7.h"

int main(int argc, char *argv[]) {
  char option;

  int d = -1;
  bool p = false;
  bool q = false;
  std::string f;

  while ((option = (char)getopt(argc, argv, "d:pqf:")) != EOF) {
    switch (option) {
      case 'd':
        d = (int)strtol(optarg, nullptr, 10);
        break;
      case 'p':
        p = true;
        break;
      case 'q':
        q = true;
        break;
      case 'f':
        f = optarg;
        break;
      default:
        std::cout << "Invalid Argument: " << option << std::endl;
        return EXIT_FAILURE;
    }
  }

  if (d == -1 || f.empty()) {
    return EXIT_FAILURE;
  }

  std::variant<int, std::pair<int, int>> solution;

  if (d == 1) {
    Day1 day1(f);
    solution = day1.solve(p, q);
  } else if (d == 2) {
    Day2 day2(f);
    solution = day2.solve(p, q);
  } else if (d == 3) {
    Day3 day3(f);
    solution = day3.solve(p, q);
  } else if (d == 4) {
    Day4 day4(f);
    solution = day4.solve(p, q);
  } else if (d == 5) {
    Day5 day5(f);
    solution = day5.solve(p, q);
  } else if (d == 6) {
    Day6 day6(f);
    solution = day6.solve(p, q);
  } else if (d == 7) {
    Day7 day7(f);
    solution = day7.solve(p, q);
  }

  if (std::holds_alternative<int>(solution)) {
    std::cout << std::get<int>(solution) << std::endl;
  } else {
    std::pair<int, int> pair = std::get<std::pair<int, int>>(solution);
    std::cout << "PART 1: " << pair.first << std::endl
              << "PART 2: " << pair.second << std::endl;
  }

  return EXIT_SUCCESS;
}

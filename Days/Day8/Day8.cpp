//
// Created by Ryan Malesic on 12/29/19.
//

#include "Day8.h"

#include <fstream>
#include <iostream>

#include "../../SpaceshipComponents/SpaceImage/SpaceImage.h"

Day8::Day8(const std::string& inputFile) : Day(inputFile) {
  std::vector<int> parsedInput;

  std::ifstream inputStream(inputFile);

  char c;
  while (inputStream.get(c)) {
    parsedInput.push_back(c - '0');
  }

  this->parsedInput = parsedInput;
}

int64_t Day8::part1() {
  SpaceImage spaceImage(this->parsedInput, 25, 6);
  return spaceImage.checksum();
}

int64_t Day8::part2() {
  SpaceImage spaceImage(this->parsedInput, 25, 6);
  space_image_t s = spaceImage.decode();

  for (int h = 0; h < 6; ++h) {
    for (auto it = s.begin() + (25 * h); it < s.begin() + (25 * (h + 1));
         ++it) {
      if (*it == 1) {
        std::cout << "\033[31m" + std::to_string(*it) + "\033[0m ";
      } else {
        std::cout << *it << " ";
      }
    }
    std::cout << std::endl;
  }

  return 0;
}
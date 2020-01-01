//
// Created by Ryan Malesic on 12/29/19.
//

#ifndef ADVENTOFCODE2019CPP_SPACEIMAGE_H
#define ADVENTOFCODE2019CPP_SPACEIMAGE_H

#include <vector>

typedef std::vector<int> space_image_t;

class SpaceImage {
 public:
  explicit SpaceImage(space_image_t spaceImage, int width, int height);

  int checksum();
  space_image_t decode();

 private:
  int width;
  int height;
  space_image_t spaceImage;
};

#endif  // ADVENTOFCODE2019CPP_SPACEIMAGE_H

//
// Created by Ryan Malesic on 12/29/19.
//

#include "SpaceImage.h"

#include <iostream>

SpaceImage::SpaceImage(space_image_t spaceImage, int width, int height)
    : spaceImage(std::move(spaceImage)), width(width), height(height) {}

int SpaceImage::checksum() {
  int layerSize = this->width * this->height;

  space_image_t layerWithMinZeros = {};
  int minZerosInLayerCount = INT_MAX;

  for (int i = 0; i < spaceImage.size() / layerSize; ++i) {
    int numZeros = 0;

    for (int j = 0; j < layerSize; ++j) {
      if (this->spaceImage[i * layerSize + j] == 0) ++numZeros;
    }

    if (numZeros < minZerosInLayerCount) {
      minZerosInLayerCount = numZeros;
      layerWithMinZeros.assign(
          this->spaceImage.begin() + (i * layerSize),
          this->spaceImage.begin() + ((i + 1) * layerSize));
    }
  }

  int numOnes = 0;
  int numTwos = 0;

  for (int i : layerWithMinZeros) {
    if (i == 1) ++numOnes;
    if (i == 2) ++numTwos;
  }

  return numOnes * numTwos;
}

space_image_t SpaceImage::decode() {
  int layerSize = this->width * this->height;

  space_image_t decodedImage = {};

  for (int i = 0; i < layerSize; ++i) {
    int depth = 0;

    while (this->spaceImage[i + layerSize * depth] == 2) {
      ++depth;
    }

    decodedImage.push_back(this->spaceImage[i + layerSize * depth]);
  }

  return decodedImage;
}
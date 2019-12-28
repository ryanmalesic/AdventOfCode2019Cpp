//
// Created by Ryan Malesic on 12/24/19.
//

#ifndef ADVENTOFCODE2019CPP_ORBITMAP_H
#define ADVENTOFCODE2019CPP_ORBITMAP_H

#include <string>
#include <unordered_map>
#include <vector>

#include "Orbit.h"

typedef std::vector<std::string> orbits_t;
typedef std::unordered_map<object_t, Orbit*> orbit_map_t;

class OrbitMap {
 public:
  explicit OrbitMap(const orbits_t& orbits);

  int getOrbitCountChecksum();
  size_t getMinStepsToSanta();

 private:
  orbit_map_t orbitMap = {};

  void calculateMinSteps(Orbit*, Orbit*, size_t, size_t*);
  static std::vector<Orbit*> getAvailableMoves(Orbit*);
};

#endif  // ADVENTOFCODE2019CPP_ORBITMAP_H

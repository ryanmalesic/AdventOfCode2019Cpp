//
// Created by Ryan Malesic on 12/24/19.
//

#include "OrbitMap.h"

#include <iostream>

OrbitMap::OrbitMap(const orbits_t& orbits) {
  for (const std::string& orbit : orbits) {
    object_t parent = orbit.substr(0, 3);
    object_t child = orbit.substr(4, 3);

    bool parentInOrbitMap = this->orbitMap.find(parent) != this->orbitMap.end();
    bool childInOrbitMap = this->orbitMap.find(child) != this->orbitMap.end();

    if (parentInOrbitMap && childInOrbitMap) {
      this->orbitMap[parent]->children.push_back(this->orbitMap[child]);
      this->orbitMap[child]->parent = this->orbitMap[parent];
    } else if (parentInOrbitMap && !childInOrbitMap) {
      auto childOrbit = new Orbit(child, this->orbitMap[parent], {}, false);

      this->orbitMap[parent]->children.push_back(childOrbit);
      this->orbitMap[child] = childOrbit;
    } else if (!parentInOrbitMap && childInOrbitMap) {
      auto parentOrbit =
          new Orbit(parent, nullptr, {this->orbitMap[child]}, false);

      this->orbitMap[child]->parent = parentOrbit;
      this->orbitMap[parent] = parentOrbit;
    } else {
      auto childOrbit = new Orbit(child, nullptr, {}, false);
      auto parentOrbit = new Orbit(parent, nullptr, {}, false);

      parentOrbit->children.push_back(childOrbit);
      childOrbit->parent = parentOrbit;

      this->orbitMap[parent] = parentOrbit;
      this->orbitMap[child] = childOrbit;
    }
  }
}

int OrbitMap::getOrbitCountChecksum() {
  int total = 0;

  for (const auto& it : this->orbitMap) {
    int depth = 0;

    Orbit o = *it.second;

    while (o.parent != nullptr) {
      depth += 1;
      o = *o.parent;
    }

    total += depth;
  }

  return total;
}

size_t OrbitMap::getMinStepsToSanta() {
  size_t minSteps = ULONG_LONG_MAX;

  this->calculateMinSteps(this->orbitMap["YOU"], this->orbitMap["SAN"], 0,
                          &minSteps);

  return minSteps - 2;
}

void OrbitMap::calculateMinSteps(Orbit* location, Orbit* destination,
                                 size_t steps, size_t* minSteps) {
  if (location == destination) {
    *minSteps = std::min(*minSteps, steps);
    return;
  }

  std::vector<Orbit*> availableMoves = getAvailableMoves(location);

  for (auto it : availableMoves) {
    it->visited = true;
    calculateMinSteps(it, destination, steps + 1, minSteps);
    it->visited = false;
  }
}

std::vector<Orbit*> OrbitMap::getAvailableMoves(Orbit* location) {
  std::vector<Orbit*> availableMoves = {};

  if (location->parent != nullptr && !location->parent->visited) {
    availableMoves.push_back(location->parent);
  }

  std::vector<Orbit*> children = location->children;

  for (Orbit* o : children) {
    if (!o->visited) {
      availableMoves.push_back(o);
    }
  }

  return availableMoves;
}

//
// Created by Ryan Malesic on 12/24/19.
//

#ifndef ADVENTOFCODE2019CPP_ORBIT_H
#define ADVENTOFCODE2019CPP_ORBIT_H

#include <string>
#include <vector>

typedef std::string object_t;
typedef std::vector<std::string> objects_t;

class Orbit {
 public:
  Orbit(object_t, Orbit*, std::vector<Orbit*>, bool);

  bool visited;
  object_t self;
  Orbit* parent;
  std::vector<Orbit*> children;
};

#endif  // ADVENTOFCODE2019CPP_ORBIT_H

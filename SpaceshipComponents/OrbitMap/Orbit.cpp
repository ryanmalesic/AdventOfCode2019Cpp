//
// Created by Ryan Malesic on 12/24/19.
//

#include "Orbit.h"

Orbit::Orbit(object_t self, Orbit* parent, std::vector<Orbit*> children,
             bool visited)
    : self(std::move(self)),
      parent(parent),
      children(std::move(children)),
      visited(visited) {}
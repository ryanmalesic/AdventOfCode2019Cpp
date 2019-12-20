//
// Created by Ryan Malesic on 12/19/19.
//

#ifndef ADVENTOFCODE2019CPP_FUELMANAGEMENTSYSTEM_H
#define ADVENTOFCODE2019CPP_FUELMANAGEMENTSYSTEM_H

#include <string>
#include <vector>

typedef std::vector<std::string> wire_t;
typedef std::pair<wire_t, wire_t> wires_t;
typedef std::pair<int, int> wire_point_t;
typedef std::vector<wire_point_t> wire_points_t;

class FuelManagementSystem {
 public:
  explicit FuelManagementSystem(const wires_t&);

  int getClosetIntersection();
  int getMinSteps();

 private:
  wire_t wire1;
  wire_t wire2;

  static wire_points_t getIntersections(wire_points_t, wire_points_t);
  static wire_points_t getWirePoints(const wire_t&);
};

#endif  // ADVENTOFCODE2019CPP_FUELMANAGEMENTSYSTEM_H

//
// Created by Ryan Malesic on 12/19/19.
//

#include "FuelManagementSystem.h"

#include <numeric>
#include <unordered_map>

FuelManagementSystem::FuelManagementSystem(const wires_t& wires) {
  this->wire1 = wires.first;
  this->wire2 = wires.second;
}

int FuelManagementSystem::getClosetIntersection() {
  wire_points_t wirePoints1 = getWirePoints(this->wire1);
  wire_points_t wirePoints2 = getWirePoints(this->wire2);
  wire_points_t intersections = getIntersections(wirePoints1, wirePoints2);

  return std::transform_reduce(
      intersections.begin(), intersections.end(), INT_MAX,
      [](const int& a, const int& b) { return std::min(a, b); },
      [](const wire_point_t& p) { return abs(p.first) + abs(p.second); });
}

int FuelManagementSystem::getMinSteps() {
  wire_points_t wirePoints1 = getWirePoints(this->wire1);
  wire_points_t wirePoints2 = getWirePoints(this->wire2);
  wire_points_t intersections = getIntersections(wirePoints1, wirePoints2);

  return std::transform_reduce(
             intersections.begin(), intersections.end(), INT_MAX,
             [](const int& a, const int& b) { return std::min(a, b); },
             [wirePoints1, wirePoints2](const wire_point_t& p) {
               return abs(std::distance(
                          std::find(wirePoints1.begin(), wirePoints1.end(), p),
                          wirePoints1.begin())) +
                      abs(std::distance(
                          std::find(wirePoints2.begin(), wirePoints2.end(), p),
                          wirePoints2.begin()));
             }) +
         2;
}

wire_points_t FuelManagementSystem::getWirePoints(const wire_t& wirePath) {
  std::unordered_map<char, wire_point_t> VELOCITIES = {
      {'U', {0, 1}}, {'R', {1, 0}}, {'D', {0, -1}}, {'L', {-1, 0}}};

  wire_point_t currentPoint = {0, 0};
  wire_points_t wirePoints = {};

  for (std::string instruction : wirePath) {
    wire_point_t velocity = VELOCITIES[instruction[0]];
    int magnitude = stoi(instruction.substr(1));

    for (int i = 0; i < magnitude; ++i) {
      currentPoint = {currentPoint.first + velocity.first,
                      currentPoint.second + velocity.second};
      wirePoints.push_back(currentPoint);
    }
  }

  return wirePoints;
}

wire_points_t FuelManagementSystem::getIntersections(
    wire_points_t wirePoints1, wire_points_t wirePoints2) {
  wire_points_t intersections = {};

  std::sort(wirePoints1.begin(), wirePoints1.end());
  std::sort(wirePoints2.begin(), wirePoints2.end());

  std::set_intersection(wirePoints1.begin(), wirePoints1.end(),
                        wirePoints2.begin(), wirePoints2.end(),
                        back_inserter(intersections));

  return intersections;
}
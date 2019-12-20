cmake_minimum_required(VERSION 3.15)
project(AdventOfCode2019Cpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(AdventOfCode2019Cpp main.cpp Days/Day/Day.cpp Days/Day/Day.h Days/Day1/Day1.cpp Days/Day1/Day1.h SpaceshipComponents/FuelCounterUpper/FuelCounterUpper.cpp SpaceshipComponents/FuelCounterUpper/FuelCounterUpper.h Days/Day2/Day2.cpp Days/Day2/Day2.h SpaceshipComponents/IntCodeComputer/IntCodeComputer.cpp SpaceshipComponents/IntCodeComputer/IntCodeComputer.h Days/Day3/Day3.cpp Days/Day3/Day3.h SpaceshipComponents/FuelManagementSystem/FuelManagementSystem.cpp SpaceshipComponents/FuelManagementSystem/FuelManagementSystem.h)
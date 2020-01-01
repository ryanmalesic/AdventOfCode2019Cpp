//
// Created by Ryan Malesic on 12/28/19.
//

#include "AmplificationCircuit.h"

AmplificationCircuit::AmplificationCircuit(program_t amplifierControlSoftware)
    : amplifierControllerSoftware(std::move(amplifierControlSoftware)){};

int AmplificationCircuit::amplifyInSeries() {
  std::vector<int64_t> phaseSettings = {0, 1, 2, 3, 4};
  int64_t max = 0;

  do {
    int64_t input = 0;
    size_t size = phaseSettings.size();

    for (int i = 0; i < size; ++i) {
      auto amplifier = IntCodeComputer();
      input = amplifier.useProgram(amplifierControllerSoftware)
                  .input({phaseSettings[i], input})
                  .execute()
                  .output()
                  .back();
    }

    max = std::max(max, input);
  } while (std::next_permutation(phaseSettings.begin(), phaseSettings.end()));

  return (int)max;
}

int AmplificationCircuit::amplifyInLoop() {
  std::vector<int64_t> phaseSettings = {5, 6, 7, 8, 9};
  int64_t max = 0;

  do {
    int64_t input = 0;

    std::vector<IntCodeComputer> amplifiers = {
        IntCodeComputer(), IntCodeComputer(), IntCodeComputer(),
        IntCodeComputer(), IntCodeComputer()};

    for (int i = 0; i < phaseSettings.size(); ++i) {
      amplifiers[i]
          .useProgram(amplifierControllerSoftware)
          .input({phaseSettings[i]})
          .execute();
    }

    while (amplifiers[4].getState() != terminated) {
      size_t size = amplifiers.size();

      for (int i = 0; i < size; ++i) {
        input = amplifiers[i].input({input}).execute().output().back();
      }

      max = std::max(max, input);
    }
  } while (std::next_permutation(phaseSettings.begin(), phaseSettings.end()));

  return (int)max;
}
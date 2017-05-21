#include <iostream>
#include <set>
#include <vector>

#include "headers/euler.hpp"

const int NUM_MULTIPLES = 6;

int main(int argc, char** argv) {
  int i = 0;
  while (++i) {
    for (int j = 2; j <= NUM_MULTIPLES; j++) {
      if (!euler::isPermutation(i, i * j)) {
        break;
      }

      if (j == NUM_MULTIPLES) {
        std::cout << i << " multiplied 1 to " << NUM_MULTIPLES << " times contains the same digits" << std::endl;
        return 0;
      }
    }
  }
  return 0;
}

#include <iostream>
#include <cmath>
#include <string>
#include <unordered_map>

#include "headers/euler.hpp"

typedef unsigned long long cube;

const int NUM_PERMUTATIONS = 5;

struct CubePermutation {
  cube smallestPermutation;
  int numPermutations;

  CubePermutation(cube smallestPermutation, int numPermutations)
    : smallestPermutation(smallestPermutation),
      numPermutations(numPermutations) {

  }
};

cube largestPermutation(cube n) {
  std::string nstr = std::to_string(n);
  std::sort(nstr.rbegin(), nstr.rend());
  return euler::toInt<cube>(nstr);
}

int main(int argc, char** argv) {
  cube n = 1;

  std::unordered_map<cube, CubePermutation*> cubePermutations;

  while (n++) {
    cube cubed = n * n * n, highestPermutation = largestPermutation(cubed);

    if (cubePermutations[highestPermutation] == nullptr) {
      cubePermutations[highestPermutation] = new CubePermutation(cubed, 0);
    }

    if (++cubePermutations[highestPermutation]->numPermutations >= NUM_PERMUTATIONS) {
      std::cout << "Found a cube with " << NUM_PERMUTATIONS << " permutations that are cubes: "
                << cubePermutations[highestPermutation]->smallestPermutation << std::endl;
      return 0;
    }
  }

  return 0;
}

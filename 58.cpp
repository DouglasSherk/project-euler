#include <iostream>
#include <unordered_set>
#include <climits>

#include "headers/euler.hpp"

const int SPIRAL_SIZE = 30001;

const float MIN_PERCENTAGE = 0.1f;

typedef unsigned long long ull;

int main(int argc, char** argv) {
  std::cout << "allocating" << std::endl;
  auto spiral = euler::generateSpiral<ull>(SPIRAL_SIZE);
  std::cout << "allocated" << std::endl;
  int center = SPIRAL_SIZE / 2;

  int i = 0;
  while (++i) {
    int size = i * 2 + 1;

    int numPrimes = 0;
    float totalDiagonals = 0.0f;

    for (int j = 1; j <= size / 2; j++) {
      totalDiagonals += 4.0f;

      // X--
      // - -
      // ---
      if (euler::isPrime(spiral[center - j][center - j])) {
        numPrimes++;
      }

      // ---
      // - -
      // X--
      if (euler::isPrime(spiral[center + j][center - j])) {
        numPrimes++;
      }

      // ---
      // - -
      // --X
      if (euler::isPrime(spiral[center + j][center + j])) {
        numPrimes++;
      }

      // --X
      // - -
      // ---
      if (euler::isPrime(spiral[center - j][center + j])) {
        numPrimes++;
      }
    }

    std::cout << "Ratio is " << numPrimes / totalDiagonals << std::endl;

    if (numPrimes / totalDiagonals < MIN_PERCENTAGE) {
      std::cout << "Number of primes less than " << MIN_PERCENTAGE * 100 << "% happens at "
                << "spiral of size " << size << std::endl;
      return 0;
    }
  }

  return 0;
}

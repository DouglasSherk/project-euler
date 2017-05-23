#include <iostream>

#include "headers/euler.hpp"

const int SPIRAL_SIZE = 30001;

const float MIN_PERCENTAGE = 0.1f;

typedef unsigned long long ull;

int main(int argc, char** argv) {
  auto spiral = euler::generateSpiral<ull>(SPIRAL_SIZE);
  int center = SPIRAL_SIZE / 2;

  int numPrimes = 0;
  int totalDiagonals = 0;

  int i = 0;
  while (++i) {
    totalDiagonals += 4;

    // X--
    // - -
    // ---
    if (euler::isPrime(spiral[center - i][center - i])) {
      numPrimes++;
    }

    // ---
    // - -
    // X--
    if (euler::isPrime(spiral[center + i][center - i])) {
      numPrimes++;
    }

    // ---
    // - -
    // --X
    if (euler::isPrime(spiral[center + i][center + i])) {
      numPrimes++;
    }

    // --X
    // - -
    // ---
    if (euler::isPrime(spiral[center - i][center + i])) {
      numPrimes++;
    }

    if (double(numPrimes) / double(totalDiagonals) < MIN_PERCENTAGE) {
      int size = i * 2 + 1;
      std::cout << "Number of primes less than " << MIN_PERCENTAGE * 100 << "% happens at "
                << "spiral of size " << size << std::endl;
      return 0;
    }
  }

  return 0;
}

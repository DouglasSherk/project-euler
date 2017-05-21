#include <iostream>
#include <string>
#include <set>

#include "headers/euler.hpp"

const int MIN_PRIME = 1000;
const int MAX_PRIME = 9999;
const int NUM_PRIME_PERMUTATIONS = 3;

const int SKIP_PRIME = 1487;

int main(int argc, char** argv) {
  auto primes = euler::generatePrimes<std::set<int>>(MAX_PRIME);

  for (auto it : primes) {
    auto prime = it;
    auto firstPrime = prime;

    if (prime < MIN_PRIME || prime == SKIP_PRIME) { continue; }

    int difference = -1;

    std::set<int> primePerms;

    while (euler::nextPermutation(prime)) {
      if (primes.find(prime) != primes.end()) {
        primePerms.insert(prime);
      }
    }

    int numPrimePerms;
    std::string primePermsStr;

    for (auto primePerm : primePerms) {
      if (primePerm == firstPrime) { continue; }

      int difference = primePerm - firstPrime;
      numPrimePerms = 1;
      primePermsStr = std::to_string(firstPrime);

      for (int i = 1; i < NUM_PRIME_PERMUTATIONS; i++) {
        int primePermSeries = firstPrime + i * difference;
        if (primePerms.find(primePermSeries) == primePerms.end()) {
          break;
        } else {
          primePermsStr += std::to_string(primePermSeries);
          numPrimePerms++;
        }
      }

      if (numPrimePerms >= NUM_PRIME_PERMUTATIONS) { break; }
    }

    if (numPrimePerms < NUM_PRIME_PERMUTATIONS) {
      continue;
    }

    std::cout << "Found " << numPrimePerms << " concatenated prime permutations: " << primePermsStr << std::endl;
    return 0;
  }

  std::cout << "No prime permutations found." << std::endl;
  return 0;
}

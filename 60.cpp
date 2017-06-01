/**
 * WARNING: This currently takes several minutes to run to completion. I'm not
 * sure why it's so much slower than other published answers as it uses the same
 * principles.
 */

#include <iostream>
#include <set>
#include <iterator>
#include <unordered_map>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <climits>

#include "headers/euler.hpp"

typedef unsigned long long prime_value;
typedef std::set<prime_value> prime_container;
typedef prime_container::iterator prime_iterator;
typedef std::vector<prime_iterator> prime_iterator_container;
typedef std::unordered_map<size_t, bool> prime_pairs_container;

const int NUM_PRIME_COMBINATIONS = 5;
const int MAX_PRIME_GENERATE = 30000;
const prime_value PRIME_VALUE_MAX = ULLONG_MAX;

prime_pairs_container primePairs;

size_t prime_value_key(prime_value a, prime_value b) {
  return (size_t) a << 32 | (prime_value) b;
}

bool areConcatsPrime(prime_value a, prime_value b) {
  size_t primeValueKey = prime_value_key(a, b);

  if (primePairs.find(primeValueKey) != primePairs.end()) {
    return primePairs[primeValueKey];
  }

  bool isConcatPrime = euler::isPrime(
    euler::toInt(std::to_string(a) + std::to_string(b))
  ) && euler::isPrime(
    euler::toInt(std::to_string(b) + std::to_string(a))
  );

  primePairs[primeValueKey] = isConcatPrime;

  return isConcatPrime;
}

bool allConcatsArePrime(const std::vector<prime_iterator>& primeIts) {
  if (primeIts.empty()) {
    return false;
  }

  for (auto i = primeIts.begin(); i != primeIts.end(); i++) {
    for (auto j = i + 1; j != primeIts.end(); j++) {
      if (!areConcatsPrime(**i, **j)) {
        return false;
      }
    }
  }

  return true;
}

void advanceIterators(prime_iterator_container& primeIters,
                      const prime_container& primes) {
  while (!primeIters.empty() && ++primeIters.back() == primes.end()) {
    primeIters.pop_back();
  }
}

int main(int argc, char** argv) {
  srand(time(NULL));

  auto primes(euler::generatePrimes<prime_container>(MAX_PRIME_GENERATE));

  prime_iterator_container primeIters;
  primeIters.push_back(primes.begin());
  prime_value result = PRIME_VALUE_MAX;

  while (!primeIters.empty()) {
    prime_value sum = 0;
    for (auto it : primeIters) {
      sum += *it;
    }
    if (sum > result) {
      primeIters.pop_back();
      advanceIterators(primeIters, primes);
    }

    prime_iterator iter = primeIters.back();

    prime_iterator_container possiblePrimeIters;

    while (!allConcatsArePrime(possiblePrimeIters) && ++iter != primes.end()) {
      possiblePrimeIters = primeIters;
      possiblePrimeIters.push_back(iter);
    }

    if (iter != primes.end()) {
      primeIters.push_back(iter);

      if (primeIters.size() >= NUM_PRIME_COMBINATIONS) {
        sum += *iter;
        if (sum < result) {
          result = sum;
        }
        std::cout << "Found a chain of sum " << sum << ": ";
        for (auto primeIter : primeIters) {
          std::cout << *primeIter << " ";
        }
        std::cout << std::endl;

        advanceIterators(primeIters, primes);
      }

      continue;
    }

    advanceIterators(primeIters, primes);
  }

  return 0;
}

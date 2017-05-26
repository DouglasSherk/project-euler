#include <iostream>
#include <set>
#include <iterator>
#include <unordered_map>

#include "headers/euler.hpp"

const int NUM_PRIME_COMBINATIONS = 5;
const int MAX_PRIME = 30000;

typedef unsigned long long prime_value;
typedef std::set<prime_value> prime_container;
typedef prime_container::iterator prime_iterator;
typedef std::pair<prime_value, prime_value> prime_pair;
typedef std::unordered_map<size_t, bool> prime_pairs_container;

size_t prime_value_key(prime_value a, prime_value b) {
  return (size_t) a << 32 | (prime_value) b;
}

void generatePrimeItEnds(const prime_container& primes, prime_iterator primeItEnds[NUM_PRIME_COMBINATIONS]) {
  prime_iterator it = primes.end();
  it--;
  primeItEnds[NUM_PRIME_COMBINATIONS - 1] = it;

  for (int i = NUM_PRIME_COMBINATIONS - 2; i >= 0; i--) {
    primeItEnds[i] = primeItEnds[i + 1];
    primeItEnds[i]--;
  }
}

bool primeIteratorsAtEnd(prime_iterator primeIts[NUM_PRIME_COMBINATIONS],
                         prime_iterator primeItEnds[NUM_PRIME_COMBINATIONS]) {
  for (int i = 0; i < NUM_PRIME_COMBINATIONS; i++) {
    if (primeIts[i] != primeItEnds[i]) {
      return false;
    }
  }

  return true;
}

bool advanceIterators(prime_iterator primeIts[NUM_PRIME_COMBINATIONS],
                      prime_iterator primeItEnds[NUM_PRIME_COMBINATIONS]) {
  if (primeIteratorsAtEnd(primeIts, primeItEnds)) {
    return false;
  }

  for (int i = NUM_PRIME_COMBINATIONS - 1; i >= 0; i--) {
    if (primeIts[i] != primeItEnds[i]) {
      primeIts[i]++;

      for (int j = i + 1; j < NUM_PRIME_COMBINATIONS; j++) {
        primeIts[j] = primeIts[j - 1];
        primeIts[j]++;
      }

      break;
    }
  }

  return true;
}

bool areConcatsPrime(prime_value a, prime_value b,
                     const prime_container& primes,
                     prime_pairs_container& primePairs) {
  // std::cout << "evaluating " << a << ", " << b << std::endl;
  if (primePairs.find(prime_value_key(a, b)) != primePairs.end()) {
    return primePairs[prime_value_key(a, b)];
  }

  bool isConcatPrime = primes.find(
    euler::toInt(std::to_string(a) + std::to_string(b))
  ) != primes.end() && primes.find(
    euler::toInt(std::to_string(b) + std::to_string(a))
  ) != primes.end();

  primePairs[prime_value_key(a, b)] = isConcatPrime;

  return isConcatPrime;
}

bool allConcatsArePrime(prime_iterator primeIts[NUM_PRIME_COMBINATIONS],
                        const prime_container& primes,
                        prime_pairs_container& primePairs) {
  for (int i = 0; i < NUM_PRIME_COMBINATIONS - 1; i++) {
    for (int j = i + 1; j < NUM_PRIME_COMBINATIONS; j++) {
      if (!areConcatsPrime(*primeIts[i], *primeIts[j], primes, primePairs)) {
        return false;
      }
    }
  }

  return true;
}

int main(int argc, char** argv) {
  std::cout << "Allocating primes" << std::endl;
  auto primes(euler::generatePrimes<prime_container>(MAX_PRIME));
  std::cout << "Allocated primes" << std::endl;
  prime_iterator primeIts[NUM_PRIME_COMBINATIONS];

  for (int i = 0; i < NUM_PRIME_COMBINATIONS; i++) {
    primeIts[i] = primes.begin();
    for (int j = 0; j < i; j++) {
      primeIts[i]++;
    }
  }

  prime_iterator primeItEnds[NUM_PRIME_COMBINATIONS];
  generatePrimeItEnds(primes, primeItEnds);

  prime_pairs_container primePairs;

  prime_value firstIt = *primeIts[0];
  do {
    if (firstIt != *primeIts[0]) {
      firstIt = *primeIts[0];
      std::cout << *primeIts[0] << ", " << *primeIts[1] << ", " << *primeIts[2] << ", " << *primeIts[3] << ", " << *primeIts[4] << std::endl;
    }
    if (allConcatsArePrime(primeIts, primes, primePairs)) {
      std::cout << "Found a series of concated primes: " << std::endl;
      std::cout << *primeIts[0] << ", " << *primeIts[1] << ", " << *primeIts[2] << ", " << *primeIts[3] << ", " << *primeIts[4] << std::endl;
      break;
    }
  } while(advanceIterators(primeIts, primeItEnds));

  return 0;
}

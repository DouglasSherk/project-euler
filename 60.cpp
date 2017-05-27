#include <iostream>
#include <set>
#include <unordered_map>

#include "headers/euler.hpp"

const int NUM_PRIME_COMBINATIONS = 5;
const int MAX_PRIME = 30000;

typedef unsigned long long prime_value;
typedef std::set<prime_value> prime_container;
typedef std::unordered_map<size_t, bool> prime_pairs_container;

size_t prime_value_key(prime_value a, prime_value b) {
  return (size_t) a << 32 | (prime_value) b;
}

prime_value concatPrimes(prime_value a, prime_value b) {
  prime_value times = 1;
  while (times <= b) {
    times *= 10;
  }
  return a * times + b;
}

bool areConcatsPrime(prime_value a, prime_value b,
                     const prime_container& primes,
                     prime_pairs_container& primePairs) {
  // std::cout << "evaluating " << a << ", " << b << std::endl;
  if (primePairs.find(prime_value_key(a, b)) != primePairs.end()) {
    return primePairs[prime_value_key(a, b)];
  }

  bool isConcatPrime = primes.find(
    // euler::toInt(std::to_string(a) + std::to_string(b))
    concatPrimes(a, b)
  ) != primes.end() && primes.find(
    // euler::toInt(std::to_string(b) + std::to_string(a))
    concatPrimes(b, a)
  ) != primes.end();

  primePairs[prime_value_key(a, b)] = isConcatPrime;

  return isConcatPrime;
}

bool allConcatsArePrime(prime_value* primeSet,
                        const prime_container& primes,
                        prime_pairs_container& primePairs) {
  for (int i = 0; i < NUM_PRIME_COMBINATIONS - 1; i++) {
    for (int j = i + 1; j < NUM_PRIME_COMBINATIONS; j++) {
      if (!areConcatsPrime(primeSet[i], primeSet[j], primes, primePairs)) {
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

  std::vector<prime_value> primesList(primes.begin(), primes.end());
  prime_pairs_container primePairs;

  for (int a = 0; a < primesList.size(); a++) {
    std::cout << "evaluating new a: " << primesList[a] << std::endl;
    for (int b = a + 1; b < primesList.size(); b++) {
      for (int c = b + 1; c < primesList.size(); c++) {
        for (int d = c + 1; d < primesList.size(); d++) {
          for (int e = d + 1; e < primesList.size(); e++) {
            prime_value primeSet[NUM_PRIME_COMBINATIONS] = {primesList[a], primesList[b], primesList[c], primesList[d], primesList[e]};
            if (allConcatsArePrime(primeSet, primes, primePairs)) {
              std::cout << "Found a series of concated primes: " << std::endl;
              std::cout << a << ", " << b << ", " << c << ", " << d << ", " << e << std::endl;
              break;
            }
          }
        }
      }
    }
  }

  return 0;
}

#include <iostream>
#include <set>
#include <string>
#include <cmath>
#include <algorithm>

#include "headers/euler.hpp"

const int TARGET_REPLACEMENTS = 8;

const int MAX_PRIMES = 1000000;

const int DIGITS = 10;

struct StringIterators {
  std::vector<int> iters;
  std::string str;

  StringIterators(std::string str, int count)
    : str(str) {
    for (int i = 0; i < count && i < str.length(); i++) {
      iters.push_back(i);
    }
  }

  StringIterators& operator++() {
    for (int i = iters.size() - 1; i >= 0; i--) {
      int end = str.length() + i - (iters.size() - 1);

      if (iters[i] < end) {
        iters[i]++;

        for (int j = i + 1; j < iters.size(); j++) {
          iters[j] = iters[j - 1] + 1;
        }

        break;
      }
    }

    return *this;
  }

  operator bool() const {
    int numItersAtEnd = 0;
    for (int i = 0; i < iters.size(); i++) {
      int end = str.length() + i - (iters.size() - 1);
      if (iters[i] == end) {
        numItersAtEnd++;
      }
    }

    return numItersAtEnd < iters.size();
  }

  std::string replaceDigits(int digit) {
    std::string digitsReplaced(str);

    for (auto it : iters) {
      digitsReplaced[it] = digit + '0';
    }

    return digitsReplaced;
  }
};

int main(int argc, char** argv) {
  auto primes(euler::generatePrimes<std::set<int>>(MAX_PRIMES));
  int globalMaxReplacements = euler::countDigits(*primes.rbegin());

  int longestChain = 0;
  std::string longestStart;

  for (auto prime : primes) {
    std::string primeStr(std::to_string(prime));
    int numDigits = primeStr.length();

    int localMaxReplacements = std::min(globalMaxReplacements, numDigits) - 1;

    for (int i = 1; i < localMaxReplacements - 1; i++) {
      StringIterators iterators(primeStr, i);

      do {
        int numPrimes = 0;
        std::string chainStart;

        for (int j = 0; j < DIGITS && DIGITS - j + numPrimes >= TARGET_REPLACEMENTS; j++) {
          std::string possiblePrimeStr(iterators.replaceDigits(j));

          int possiblePrime = euler::toInt(possiblePrimeStr);

          if (euler::countDigits(possiblePrime) == numDigits && primes.find(possiblePrime) != primes.end()) {
            chainStart = chainStart.empty() ? possiblePrimeStr : chainStart;

            numPrimes++;

            if (numPrimes > longestChain) {
              longestChain = numPrimes;
              longestStart = chainStart;

              if (longestChain >= TARGET_REPLACEMENTS) {
                break;
              }
            }
          }
        }
      } while (++iterators && longestChain < TARGET_REPLACEMENTS);
    }

    if (longestChain >= TARGET_REPLACEMENTS) {
      break;
    }
  }

  std::cout << "Longest chain of primes by digit substitution begins at: " << longestStart
            << ", with length of: " << longestChain << "" << std::endl;

  return 0;
}

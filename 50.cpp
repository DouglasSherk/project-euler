#include <iostream>
#include <set>
#include <vector>

#include "headers/euler.hpp"

const int MAX_PRIME = 999999;

typedef long long ll;

int main(int argc, char** argv) {
  auto primes = euler::generatePrimes<std::set<int>>(MAX_PRIME);
  std::vector<int> sums;
  int longestChainLength = 0;
  int longestChainPrime;

  int sum = 0;
  for (auto it : primes) {
    sum += it;
    if (sum > MAX_PRIME) { break; }

    sums.push_back(sum);
  }

  for (int i = 0; i < sums.size(); i++) {
    for (int j = sums.size() - 1; j > i; j--) {
      int possiblePrime = sums[j] - sums[i];

      if (primes.find(possiblePrime) != primes.end() &&
          j - i > longestChainLength) {
        longestChainPrime = possiblePrime;
        longestChainLength = j - i;
      }
    }
  }

  std::cout << "Longest chain length " << longestChainLength << " for prime " << longestChainPrime << std::endl;

  return 0;
}

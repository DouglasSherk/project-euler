#include <iostream>
#include <math.h>
#include <set>
#include <string>
#include <sstream>

using namespace std;

int gTarget = 100000;
int gPrimeFactors = 4;

set<int> generatePrimes(int n) {
  bool* sieve = new bool[n + 1]();

  for (int i = 2; i < sqrt(n); i++) {
    for (int j = 2; i * j <= n; j++) {
      sieve[i * j] = true;
    }
  }

  set<int> primes;
  for (int i = 2; i <= n; i++) {
    if (!sieve[i]) {
      primes.insert(i);
    }
  }

  return primes;
}

int pow(int n, int k) {
  int power = 1;
  for (int i = 0; i < k; i++) {
    power *= n;
  }
  return power;
}

bool hasPrimeFactors(int n, set<int>& primes) {
  int numFactors = 0;
  for (auto prime : primes) {
    if (n % prime == 0) {
      while (n % prime == 0) {
        n /= prime;
      }
      numFactors++;
    }

    if (numFactors >= gPrimeFactors && n == 1) {
      return true;
    }
  }
  return false;
}

int main(int argc, char** argv) {
  auto primes = generatePrimes(gTarget);

  int consecutivePrimeFactors = 0;
  for (int i = 1; ; i++) {
    if (hasPrimeFactors(i, primes)) {
      consecutivePrimeFactors++;
      // cout << i << " has prime factors" << endl;
    } else {
      consecutivePrimeFactors = 0;
    }
    if (consecutivePrimeFactors >= gPrimeFactors) {
      cout << i - gPrimeFactors + 1 << " start of " << gPrimeFactors << " consecutive prime factors" << endl;
      break;
    }
  }

  return 0;
}

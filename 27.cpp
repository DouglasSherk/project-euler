#include <iostream>
#include <math.h>
#include <unordered_set>

using namespace std;

int maxPrime = 10000000;

int target = 1000;

unordered_set<int> generatePrimes(int n) {
  bool* sieve = new bool[n + 1]();

  for (int i = 2; i < sqrt(n); i++) {
    for (int j = 2; i * j <= n; j++) {
      sieve[i * j] = true;
    }
  }

  unordered_set<int> primes;
  for (int i = 2; i <= n; i++) {
    if (!sieve[i]) {
      primes.insert(i);
    }
  }

  return primes;
}

int getResult(int n, int a, int b) {
  return n*n + a*n + b;
}

bool isPrime(int n, unordered_set<int>& primes) {
  return primes.find(n) != primes.end();
}

int main(int argc, char** argv) {
  unordered_set<int> primes = generatePrimes(maxPrime);

  int longestN = 0;
  int longestA = -1;
  int longestB = -1;

  for (int a = -target + 1; a < target; a++) {
    for (int b = -target; b <= target; b++) {
      int n = 0;
      while (isPrime(getResult(n, a, b), primes)) {
        if (n > longestN) {
          longestN = n;
          longestA = a;
          longestB = b;
        }
        n++;
      }
    }
  }

  cout << "Longest chain: n^2 + " << longestA << "n + " << longestB << " with length of " << longestN << endl;
  cout << "Product of coefficients: " << longestA * longestB << endl;

  return 0;
}

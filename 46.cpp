#include <iostream>
#include <math.h>
#include <set>
#include <string>
#include <sstream>

using namespace std;

int target = 10000;

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

bool isSumOfPrimeAndTwiceASquare(int n, set<int>& primes) {
  bool foundMatch = false;
  for (int square = 1; !foundMatch && square <= sqrt(n); square++) {
    for (auto prime : primes) {
      int sumOfPrimeAndTwiceSquare = prime + 2 * square * square;
      if (sumOfPrimeAndTwiceSquare >= n) {
        foundMatch = sumOfPrimeAndTwiceSquare == n;
        break;
      }
    }
  }
  return foundMatch;
}

int main(int argc, char** argv) {
  set<int> primes = generatePrimes(target);

  int i, n;
  for (i = 2; ; i++) {
    n = i * 2 + 1; // skip odd numbers
    if (primes.find(n) != primes.end()) { continue; }
    if (!isSumOfPrimeAndTwiceASquare(n, primes)) { break; }
  }

  cout << n << " can't be written as the sum of a prime and twice a square" << endl;

  return 0;
}

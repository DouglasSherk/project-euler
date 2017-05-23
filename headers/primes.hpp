#ifndef __EULER_PRIMES_INCLUDED_
#define __EULER_PRIMES_INCLUDED_

#include <cstdlib>
#include <math.h>

#include "arithmetic.hpp"

namespace euler {

const int NUM_PRIMALITY_TESTS = 50;

template <class T>
T generatePrimes(int n) {
  bool* sieve = new bool[n + 1]();

  for (int i = 2; i < sqrt(n); i++) {
    for (int j = 2; i * j <= n; j++) {
      sieve[i * j] = true;
    }
  }

  T primes;
  for (int i = 2; i <= n; i++) {
    if (!sieve[i]) {
      primes.insert(i);
    }
  }

  return primes;
}

template <class T>
bool isPrime(T n, int numTests = NUM_PRIMALITY_TESTS) {
  if (n == 2) {
    return true;
  }

  if (n < 2 || n % 2 == 0) {
    return false;
  }

  T p = n - 1;
  while (p % 2 == 0) {
    p /= 2;
  }

  for (int i = 0; i < numTests; i++) {
    T a = rand() % (n - 1) + 1, temp = p;
    T res = power<T>(a, temp, n);

    while (temp != n - 1 && res != 1 && res != n - 1) {
      res *= res;
      res %= n;
      temp *= 2;
    }

    if (res != n - 1 && temp % 2 == 0) {
      return false;
    }
  }

  return true;
}

}

#endif // __EULER_PRIMES_INCLUDED_

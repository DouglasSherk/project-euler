#ifndef __EULER_PRIMES_INCLUDED_
#define __EULER_PRIMES_INCLUDED_

#include <math.h>

namespace euler {

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

}

#endif // __EULER_PRIMES_INCLUDED_

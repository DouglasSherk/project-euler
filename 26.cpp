/*
Number theory-based solution.

Fractions with prime denominators always have repeating decimals. Non-primes
never do. Factors of primes never have higher amounts of repeating decimals than
the primes they are factors of. Thus we can evaluate only all primes from 1 to
1000 for repeating digits.

Calculate the order for `10 modulo p`, where `p` is the prime number in the
expression `1/p`. This is equal to the number of repeating digits.

References:
https://en.wikipedia.org/wiki/Repeating_decimal#Fractions_with_prime_denominators
https://en.wikipedia.org/wiki/Multiplicative_order
*/

#include <iostream>
#include <math.h>
#include "Vector.h"
#include <boost/multiprecision/gmp.hpp>

using namespace std;

int target = 1000;

int main(int argc, char** argv) {
  // Lazy primes generation, since the amount we need is so low.
  Vector<int> primes;
  primes.insertBack(2);
  for (int i = primes[0]; i < target; i++) {
    bool foundFactor = false;
    for (int j = 0; j < primes.length(); j++) {
      cout << i << ", " << j << endl;
      if (i % primes[j] == 0) {
        foundFactor = true;
        break;
      }
    }
    if (!foundFactor) {
      cout << "No factors for " << i << endl;
      primes.insertBack(i);
    }
  }

  int highestPeriodIndex;
  int highestPeriod = 0;

  for (int i = 0; i < primes.length(); i++) {
    int prime = primes[i];
    if (prime == 2 || prime == 5) {
      // Special case: according to number theory, the rule doesn't apply to
      // these two, probably because they're both factors of 10.
      continue;
    }
    int a = 10;
    boost::multiprecision::mpz_int ak = a;
    int k = 1;
    while (ak % prime != 1) {
      ak *= a;
      k++;
    }
    if (k > highestPeriod) {
      highestPeriod = k;
      highestPeriodIndex = i;
    }
  }

  cout << "Number from 1 to " << target << " with highest number of repeating digits: "
       << primes[highestPeriodIndex] << " with period of " << highestPeriod << endl;

  return 0;
}

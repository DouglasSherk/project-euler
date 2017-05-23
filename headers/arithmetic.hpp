#ifndef __EULER_ARITHMETIC_INCLUDED_
#define __EULER_ARITHMETIC_INCLUDED_

namespace euler {

template <class T>
struct fraction {
  T numer;
  T denom;

  fraction(T numer, T denom)
    : numer(numer),
      denom(denom) {

  }
};

template <class T>
T power(T n, T k, T modulo = 0) {
  T sum = 1;

  for (T i = 0; i < k; i++) {
    sum *= n;
    if (modulo) {
      sum %= modulo;
    }
  }

  return sum;
}

template <class T>
T gcd(T a, T b) {
  if (!a || !b) {
    return 0;
  }

  while (a != b) {
    if (a > b) {
      a -= b;
    } else {
      b -= a;
    }
  }

  return a > b ? a : b;
}

template <class T>
T countDigits(T n) {
  T numDigits = 0;

  while (n) {
    numDigits++;
    n /= 10;
  }

  return numDigits;
}

}

#endif // __EULER_ARITHMETIC_INCLUDED_

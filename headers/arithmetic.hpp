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
T mulmod(T a, T b, T modulo) {
  T x = 0, y = a % modulo;

  while (b > 0){
    if (b % 2 == 1) {
      x = (x + y) % modulo;
    }

    y = (y * 2) % modulo;
    b /= 2;
  }

  return x % modulo;
}

template <class T>
T power(T n, T k, T modulo = 0) {
  T x = 1, y = n;

  while (k > 0) {
    if (k % 2 == 1) {
      x = (x * y);

      if (modulo) {
        x %= modulo;
      }
    }

    y = (y * y);
    if (modulo) {
      y %= modulo;
    }

    k /= 2;
  }

  if (modulo) {
    x %= modulo;
  }

  return x;
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

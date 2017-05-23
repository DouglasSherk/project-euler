#include <iostream>

#include <boost/multiprecision/gmp.hpp>

#include "headers/euler.hpp"

const int EXPANSIONS_BEGIN = 1;
const int EXPANSIONS_NUM = 1000;

typedef boost::multiprecision::mpz_int big_int;
typedef euler::fraction<big_int> fraction;

fraction expandSqrt(int n, int depth = 0) {
  if (depth == n) {
    return fraction(1, 2);
  }

  fraction cd = expandSqrt(n, depth + 1);

  big_int a = cd.denom + (depth ? 0 : cd.numer);
  big_int b = depth ? (2 * cd.denom + cd.numer) : cd.denom;

  return fraction(a, b);
}

int main(int argc, char** argv) {
  int termsWithHigherDigitCountNumers = 0;

  for (int i = EXPANSIONS_BEGIN; i <= EXPANSIONS_NUM; i++) {
    fraction expandedTerm = expandSqrt(i);

    if (euler::countDigits(expandedTerm.numer) > euler::countDigits(expandedTerm.denom)) {
      termsWithHigherDigitCountNumers++;
    }
  }

  std::cout << "Total expansions between " << EXPANSIONS_BEGIN << " and " << EXPANSIONS_NUM
            << " of sqrt(2) with higher counts of digits in numerator than denominator: "
            << termsWithHigherDigitCountNumers << std::endl;

  return 0;
}

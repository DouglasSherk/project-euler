#include <iostream>

#include <boost/multiprecision/gmp.hpp>

#include "headers/euler.hpp"

const int MIN_A_B = 1;
const int MAX_A_B = 100;

typedef boost::multiprecision::mpz_int big_int;

int main(int argc, char** argv) {
  int largestA;
  int largestB;
  big_int largestDigitSum = 0;

  for (int a = MIN_A_B; a <= MAX_A_B; a++) {
    for (int b = MIN_A_B; b <= MAX_A_B; b++) {
      big_int n = euler::power<big_int>(a, b);

      big_int digitSum = 0;

      while (n) {
        digitSum += n % 10;
        n /= 10;
      }

      if (digitSum > largestDigitSum) {
        largestDigitSum = digitSum;
        largestA = a;
        largestB = b;
      }
    }
  }

  std::cout << "Largest digit sum of A^B is " << largestDigitSum << " "
            << "for A=" << largestA << ", B=" << largestB
            << std::endl;

  return 0;
}

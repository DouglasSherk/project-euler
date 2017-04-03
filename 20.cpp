#include <iostream>
#include <math.h>

#include <boost/multiprecision/gmp.hpp>

using namespace std;

int target = 100;

int main(int argc, char** argv) {
  boost::multiprecision::mpz_int n = 1;
  for (int i = 1; i <= target; i++) {
    n *= i;
  }
  unsigned long long sum = 0;
  while (n) {
    sum += static_cast<unsigned long long>(n % 10);
    n /= 10;
  }
  cout << "Sum of all digits: " << sum << endl;
  return 0;
}

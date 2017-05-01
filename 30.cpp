#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <math.h>
#include <set>
#include <boost/multiprecision/gmp.hpp>
#include <boost/multiprecision/number.hpp>

using namespace std;
using namespace boost::multiprecision;

int target = 5;

unsigned long long power(int n, int k) {
  unsigned long long sum = 1;
  for (int i = 0; i < k; i++) {
    sum *= n;
  }
  return sum;
}

unsigned long long digits_power_sum(int n) {
  unsigned long long sum = 0;
  int digit;
  while (n) {
    digit = n % 10;
    n /= 10;

    sum += power(digit, target);
  }
  return sum;
}

int main(int argc, char** argv) {
  int max = power(10, target + 1) - 1;
  unsigned long long sum = 0;
  for (int i = 2; i < max; i++) {
    if (digits_power_sum(i) == i) {
      cout << i << " can be written as the sum of its " << target << "th power sums " << endl;
      sum += i;
    }
  }
  cout << "Sum of all " << target << "th-powerable integers is: " << sum << endl;
  return 0;
}

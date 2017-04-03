#include <iostream>
#include <math.h>
#include "Vector.h"
#include <boost/multiprecision/gmp.hpp>

using namespace std;

int target = 1000;

int main(int argc, char** argv) {
  boost::multiprecision::mpz_int min = 1;
  for (int i = 1; i < target; i++) {
    min *= 10;
  }
  Vector<boost::multiprecision::mpz_int> fibonacci;
  fibonacci.insertBack(1);
  fibonacci.insertBack(1);
  while (fibonacci[fibonacci.length() - 1] < min) {
    int end = fibonacci.length() - 1;
    fibonacci.insertBack(fibonacci[end] + fibonacci[end - 1]);
  }
  cout << "Index of first Fibonacci number with " << target << " digits: " << fibonacci.length() << endl;
  return 0;
}

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

// We don't need to divide by all numbers from 1 to 20, since a number
// divisible by 20 is also divisible by 2. Instead, walk backwards from 20 and
// remove all numbers that are multiples of each element walked.
const unsigned long divisors[] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
const unsigned long divisorsCount = sizeof(divisors) / sizeof(unsigned long);

bool isDivisibleByAllDivisors(unsigned long n) {
  for (unsigned long i = 0; i < divisorsCount; i++) {
    if (n % divisors[i]) {
      return false;
    }
  }
  return true;
}

int main(int argc, char** argv) {
  unsigned long i = 20;
  while (!isDivisibleByAllDivisors(++i)) {}
  cout << "First evenly divisible number: " << i << endl;

  return 0;
}

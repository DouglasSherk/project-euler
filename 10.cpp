#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

unsigned long target = 2000000;

int main(int argc, char** argv) {
  vector<bool> sieve;
  sieve.resize(target, true);
  sieve[0] = sieve[1] = false;
  for (size_t i = 2; i <= target; ) { // 0 doesn't matter, but whatever
    for (size_t j = 2; i * j < target; j++) {
      cout << i * j << " - multiple of " << i << endl;
      sieve[i * j] = false;
    }
    while (!sieve[++i]) {}
  }
  size_t sum = 0;
  for (size_t i = 0; i < sieve.size(); i++) {
    if (sieve[i]) {
      cout << i << endl;
      sum += i;
    }
  }
  cout << "Sum of all primes below " << target << ": " << sum << endl;
  return 0;
}

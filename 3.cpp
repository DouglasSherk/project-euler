#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
  unsigned long target = 600851475143;

  /**
   * Sieve of Eratosthenes solution. Too much memory use, crashes my MBP...
   *
   * vector<bool> sieve;
   * sieve.resize(target, true);
   * for (size_t i = 0; i <= sqrt(target); i++) { // 0 doesn't matter, but whatever
   *   for (size_t j = 2; i * j < target; j++) {
   *     cout << j << endl;
   *     sieve[j] = false;
   *   }
   * }
   * bool foundMatch = false;
   * for (size_t i = sieve.size() - 1; i > 1; i--) {
   *   if (sieve[i]) {
   *     foundMatch = true;
   *     cout << i << endl;
   *     break;
   *   }
   * }
   * if (!foundMatch) {
   *   cout << "No match found" << endl;
   * }
   */

  unsigned long targetSqrt = sqrt(target);
  unsigned long lastDivisor = 0;
  for (unsigned long divisor = 2; divisor <= targetSqrt; divisor++) {
    if (target % divisor == 0) {
      cout << divisor << endl;
      lastDivisor = divisor;
      target /= divisor;
    }
  }
  if (lastDivisor > 0) {
    cout << "Prime factor: " << lastDivisor << endl;
  } else {
    cout << "No prime factors" << endl;
  }
  return 0;
}

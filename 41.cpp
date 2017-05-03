#include <iostream>
#include <math.h>
#include <unordered_set>
#include <sstream>
#include <string>

using namespace std;

int target = 1000000000;

#define MAX_DIGITS 9

unordered_set<int> generatePrimes(int n) {
  cout << "Generating primes" << endl;
  bool* sieve = new bool[n + 1]();
  cout << "Allocated" << endl;

  for (int i = 2; i < sqrt(n) + 1; i++) {
    cout << "Generating primes for " << i << " / " << sqrt(n) << endl;
    for (int j = 2; i * j <= n; j++) {
      sieve[i * j] = true;
    }
  }

  unordered_set<int> primes;
  for (int i = 2; i <= n; i++) {
    if (!sieve[i]) {
      primes.insert(i);
    }
  }
  cout << "Generated primes" << endl;

  return primes;
}

bool isPandigital(int n) {
  int numDigits = log10(n) + 1;
  if (numDigits > MAX_DIGITS) {
    return false;
  }
  string number = to_string(n);

  bool digits[MAX_DIGITS + 1] = {false};

  for (auto it : number) {
    int digit = it - '0';
    if (digits[digit]) {
      return false;
    }
    digits[digit] = true;
  }

  for (int i = 1; i <= numDigits; i++) {
    if (!digits[i]) {
      return false;
    }
  }

  return true;
}

int main(int argc, char** argv) {
  int largestPandigitalPrime = -1;
  /*
  Debug code for pandigital check.
  largestPandigitalPrime = target / 10;
  for (int i = largestPandigitalPrime; i < 999999999; i++) {
    if (isPandigital(i)) {
      cout << i << " is pandigital" << endl;
    }
  }
  */
  unordered_set<int> primes = generatePrimes(target);
  for (auto it : primes) {
    if (it > largestPandigitalPrime && isPandigital(it)) {
      largestPandigitalPrime = it;
    }
  }
  cout << "Largest pandigital prime is: " << largestPandigitalPrime << endl;
  return 0;
}

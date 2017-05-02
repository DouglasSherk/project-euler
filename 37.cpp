#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <math.h>
#include <sstream>
#include <string>
#include <set>

using namespace std;

int target = 10000000;

set<int> generatePrimes(int n) {
  bool* sieve = new bool[n + 1]();

  for (int i = 2; i < sqrt(n); i++) {
    for (int j = 2; i * j <= n; j++) {
      sieve[i * j] = true;
    }
  }

  set<int> primes;
  for (int i = 2; i <= n; i++) {
    if (!sieve[i]) {
      primes.insert(i);
    }
  }

  return primes;
}

bool truncatedDigitsArePrime(string prime, set<int>& primes, bool front) {
  // cout << "starting at " << prime << endl;
  int n = 0;
  string original = prime;
  while (prime.length() > 1) {
    /*
    if (++n > 6) {
      cout << "found high one " << original << " " << n << endl;
      cout << " --> " << prime << endl;
    }
    */
    prime.erase(front ? 0 : prime.length() - 1, 1);

    // cout << "evaluating " << prime << endl;

    stringstream strstream;
    int primeInt;

    strstream << prime;
    strstream >> primeInt;

    if (primes.find(primeInt) == primes.end()) {
      /*
      if (n > 6) {
        cout << "failed at : " << primeInt << endl;
      }
      */
      return false;
    }
  }

  return true;
}

int main(int argc, char** argv) {
  set<int> primes = generatePrimes(target);

  int sum = 0;

  for (auto it : primes) {
    if (it == 2 || it == 3 || it == 5 || it == 7) { continue; }

    string prime = to_string(it);
    if (truncatedDigitsArePrime(prime, primes, true) &&
        truncatedDigitsArePrime(prime, primes, false)) {
      cout << it << " is prime when truncated in both directions" << endl;
      sum += it;
    }
  }

  cout << "Sum of all truncatable primes: " << sum << endl;

  return 0;
}

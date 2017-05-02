#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <math.h>
#include <unordered_set>
#include <sstream>

using namespace std;

int target = 1000000;

unordered_set<int> generatePrimes(int n) {
  bool* sieve = new bool[n + 1]();

  for (int i = 2; i < sqrt(n); i++) {
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

  return primes;
}

bool isCircular(int n, unordered_set<int>& primes) {
  string n_rot = to_string(n);

  for (size_t i = 0; i < n_rot.length(); i++) {
    rotate(n_rot.begin(), n_rot.begin() + 1, n_rot.end());

    stringstream strstream;
    strstream << n_rot;
    int n_rot_int;
    strstream >> n_rot_int;

    if (primes.find(n_rot_int) == primes.end()) {
      return false;
    }
  }

  return true;
}

int main(int argc, char** argv) {
  unordered_set<int> primes = generatePrimes(target);
  int totalCircular = 0;
  for (auto it : primes) {
    if (isCircular(it, primes)) {
      cout << it << " is circular" << endl;
      totalCircular++;
    }
  }
  cout << "Total number of circular primes: " << totalCircular << endl;
  return 0;
}

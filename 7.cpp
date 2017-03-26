#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

unsigned long target = 10001;

bool isPrimeFromList(unsigned long n, vector <unsigned long>& primes, unsigned long pos) {
  for (unsigned long i = 0; i < pos; i++) {
    if (n % primes[i] == 0) {
      return false;
    }
  }
  return true;
}

int main(int argc, char** argv) {
  vector <unsigned long> primes;
  primes.resize(target, 0);
  primes[0] = 2;
  cout << primes[0] << endl;
  for (unsigned long i = 1; i < target; i++) {
    unsigned long j = primes[i - 1];
    while (!isPrimeFromList(++j, primes, i)) { }
    primes[i] = j;
    cout << primes[i] << endl;
  }
  cout << target << "th Prime is: " << primes[target - 1] << endl;
  return 0;
}

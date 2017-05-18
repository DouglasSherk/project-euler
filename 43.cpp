#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

string gPandigitalStart("0123456789");

#define MAX_DIGITS 10

int sliceSize = 3;
int sliceBegin = 1;

bool nextPermutation(string& number) {
  // 1. Find largest x s.t. P[x]<P[x+1]
  int x = -1;
  for (int i = number.length() - 2; i >= 0; i--) {
    if (number[i] < number[i + 1]) {
      x = i;
      break;
    }
  }

  // 1a. If there is no such x, then this was the last permutation.
  if (x == -1) {
    return false;
  }

  // 2. Find largest y s.t. P[x]<P[y]
  int y = -1;
  for (int i = number.length() - 1; i >= 0; i--) {
    if (number[x] < number[i]) {
      y = i;
      break;
    }
  }

  // 3. Swap P[x] and P[y]
  char temp = number[x];
  number[x] = number[y];
  number[y] = temp;

  // 4. Reverse P[x+1]..P[n]
  reverse(number.begin() + x + 1, number.end());

  return true;
}

bool isPandigital(string& number) {
  bool digits[MAX_DIGITS] = {false};

  for (auto it : number) {
    int digit = it - '0';
    if (digits[digit]) {
      return false;
    }
    digits[digit] = true;
  }

  for (int i = 0; i < MAX_DIGITS; i++) {
    if (!digits[i]) {
      return false;
    }
  }

  return true;
}

vector<int> generatePrimes(int n) {
  vector<int> primes;
  primes.push_back(2);
  int lastPrime = 2;

  for (int g = primes.size(); g < n; g++) {
    for (int i = lastPrime + 1; ; i++) {
      bool foundFactor = false;

      for (auto prime : primes) {
        if (i % prime == 0) {
          foundFactor = true;
          break;
        }
      }

      if (!foundFactor) {
        lastPrime = i;
        primes.push_back(i);
        break;
      }
    }
  }

  return primes;
}

unsigned long long strToI(string num) {
  stringstream strstream;
  unsigned long long n;
  strstream << num;
  strstream >> n;
  return n;
}

int main(int argc, char** argv) {
  unsigned long long sumSubstringDivisiblePandigitals = 0;
  vector<int> primes = generatePrimes(MAX_DIGITS);

  string pandigital(gPandigitalStart);
  while (nextPermutation(pandigital)) {
    bool foundIndivisible = false;
    for (int i = sliceBegin; i + sliceSize <= MAX_DIGITS; i++) {
      unsigned long long digits = strToI(string(pandigital.begin() + i, pandigital.begin() + i + sliceSize));
      if (digits % primes[i - sliceBegin] != 0) {
        foundIndivisible = true;
        break;
      }
    }

    if (!foundIndivisible) {
      cout << pandigital << " is pandigital AND has the sub-string divisibility property." << endl;
      sumSubstringDivisiblePandigitals += strToI(pandigital);
    }
  }

  cout << "Sum of all sub-string divisible pandigitals: " << sumSubstringDivisiblePandigitals << endl;

  return 0;
}

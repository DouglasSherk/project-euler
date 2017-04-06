#include <iostream>
#include <math.h>
#include "Vector.h"

using namespace std;

#define TARGET 28123

int sumsOfProperDivisors[TARGET] = {0};

int sumOfProperDivisor(int n) {
  if (sumsOfProperDivisors[n]) {
    return sumsOfProperDivisors[n];
  }

  bool seen[TARGET] = {false};
  int sum = 1;
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      // cout << i << " and " << n / i << " are factors" << endl;
      sum += i;
      // Add in the other factor on the other side of the sqrt if it's not a
      // perfect square.
      if (n / i != i) {
        sum += n / i;
      }
    }
  }

  sumsOfProperDivisors[n] = sum;
  return sum;
}

int main(int argc, char** argv) {
  Vector<int> abundantNumbers;
  cout << "Abundant numbers: ";
  for (int i = 1; i <= TARGET; i++) {
    if (sumOfProperDivisor(i) > i) {
      cout << i << ", ";
      abundantNumbers.insertBack(i);
    }
  }
  cout << endl;

  int sum = 0;
  for (int i = 1; i <= TARGET; i++) {
    bool foundMatch = false;
    int j = 0;
    int k = abundantNumbers.length() - 1;
    while (j <= k) {
      int sumAbundantNumbers = abundantNumbers[j] + abundantNumbers[k];
      if (sumAbundantNumbers == i) {
        foundMatch = true;
        break;
      } else if (sumAbundantNumbers > i) {
        k--;
      } else if (sumAbundantNumbers < i) {
        j++;
      }
    }

    if (!foundMatch) {
      cout << i << " cannot be written as the sum of two abundant numbers" << endl;
      sum += i;
    }
  }
  cout << "Sum of all numbers that can't be written as the sum of two abundant numbers: " << sum << endl;
  return 0;
}

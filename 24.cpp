#include <iostream>
#include <math.h>
#include "Vector.h"

using namespace std;

#define DIGITS 10

int target = 1000000;

void permutate(int digits[], int n) {
  int carry = 1;
  for (int i = n - 1; i >= 0; i--) {
    if ((digits[i] += carry) >= n) {
      carry = digits[i] / n;
      digits[i] %= n;
    }
  }
}

bool isPermutation(int digits[], int n) {
  bool seen[DIGITS] = {false};
  for (int i = 0; i < n; i++) {
    if (seen[i]) {
      return false;
    }
    seen[i] = true;
  }
  for (int i = 0; i < n; i++) {
    if (!seen[i]) {
      return false;
    }
  }
  return true;
}

void printPermutation(int digits[], int n) {
  for (int i = 0; i < DIGITS; i++) {
    cout << digits[i];
  }
  cout << endl;
}

int main(int argc, char** argv) {
  int digits[DIGITS];
  for (int i = 0; i < DIGITS; i++) {
    digits[i] = i;
  }
  int n = 0;
  for (int i = 0; n < target; i++) {
    permutate(digits, DIGITS);
    if (isPermutation(digits, DIGITS)) {
      printPermutation(digits, DIGITS);
      n++;
    }
  }
  cout << "The " << target << "th permutation is: ";
  printPermutation(digits, DIGITS);
  return 0;
}

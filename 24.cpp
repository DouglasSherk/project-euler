#include <iostream>
#include <math.h>
#include "Vector.h"

using namespace std;

#define DIGITS 10

int target = 1000000;

void printPermutation(int digits[], int n) {
  for (int i = 0; i < n; i++) {
    cout << digits[i];
  }
  cout << endl;
}

void reverse(int digits[], int n) {
  for (int i = 0; i < n / 2; i++) {
    int temp = digits[n - i - 1];
    digits[n - i - 1] = digits[i];
    digits[i] = temp;
  }
}

void permutate(int digits[], int n) {
  int x = -1;
  for (int i = n - 1; i > 0; i--) {
    if (digits[i - 1] < digits[i]) {
      x = i - 1;
      break;
    }
  }

  // There are no more permutations -- bail out.
  if (x == -1) {
    return;
  }

  int y = -1;
  for (int i = n - 1; i >= 0; i--) {
    if (digits[x] < digits[i]) {
      y = i;
      break;
    }
  }

  if (y == -1) {
    return;
  }

  int temp = digits[x];
  digits[x] = digits[y];
  digits[y] = temp;

  reverse(&digits[x + 1], n - x - 1);
}

int main(int argc, char** argv) {
  int digits[DIGITS];
  for (int i = 0; i < DIGITS; i++) {
    digits[i] = i;
  }
  // The starting state is the first permutation.
  for (int i = 0; i < target - 1; i++) {
    permutate(digits, DIGITS);
  }
  cout << "The " << target << "th permutation is: ";
  printPermutation(digits, DIGITS);
  return 0;
}

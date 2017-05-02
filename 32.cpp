#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <math.h>
#include <unordered_set>

using namespace std;

#define DIGITS 9

int reduceToBits(int n) {
  int reduce = 0;

  while (n) {
    int digit = n % 10;
    n /= 10;

    if (digit == 0 || reduce & (1<<digit)) {
      return -1;
    }
    reduce |= (1<<digit);
  }

  return reduce;
}

bool isPandigital(int a, int b) {
  int product = a * b;
  bool digitsPresent[10] = {false};

  int productBits = reduceToBits(product);
  int aBits = reduceToBits(a);
  int bBits = reduceToBits(b);

  if (productBits == -1 || aBits == -1 || bBits == -1) {
    return false;
  }

  int bits = productBits | aBits | bBits;

  for (int i = 1; i <= DIGITS; i++) {
    int bit = (1<<i);
    if (((productBits & bit) && (aBits & bit)) ||
        ((aBits & bit) && (bBits & bit)) ||
        ((productBits & bit) && (bBits & bit))) {
      return false;
    }
    if (!(bits & bit)) {
      return false;
    }
  }

  return true;
}

int target = 100000000;

int power(int n, int k) {
  int sum = 1;
  for (int i = 0; i < k; i++) {
    sum *= n;
  }
  return sum;
}

int main(int argc, char** argv) {
  unordered_set<int> pandigital_products;
  for (int a = 1; a < target / 2; a++) {
    for (int b = 1; int(log10(a)) + int(log10(b)) + int(log10(a * b)) <= DIGITS; b++) {
      // cout << "pow: " << log10(a) << ", " << log10(b) << ", " << log10(a * b) << endl;
      // cout << "Evaluating: " << a << ", " << b << " (" << a * b << ")" << endl;
      if (isPandigital(a, b)) {
        cout << a * b << " (" << a << ", " << b << ") is pandigital" << endl;
        pandigital_products.insert(a * b);
      }
    }
  }
  int sum = 0;
  for (auto it : pandigital_products) {
    sum += it;
  }
  cout << "Sum of all pandigital numbers of n=" << DIGITS << ": " << sum << endl;
  return 0;
}

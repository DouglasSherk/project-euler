#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

bool isPalindrome(unsigned long n) {
  // 334433 =
  //  3 * 10^5 +
  //  3 * 10^4 +
  //  4 * 10^3 +
  //  4 * 10^2 +
  //  3 * 10^1 +
  //  3 * 10^0

  unsigned long original = n;
  unsigned long reversed = 0;
  while (original > 0) {
    unsigned long lastDigit = original % 10;
    original /= 10;
    reversed = reversed * 10 + lastDigit;
  }

  return reversed == n;
}

int main(int argc, char** argv) {
  unsigned long largestPalindrome = 0;
  for (unsigned long i = 1; i < 1000; i++) {
    for (unsigned long j = 1; j < 1000; j++) {
      unsigned long product = i * j;
      if (isPalindrome(product) && product > largestPalindrome) {
        largestPalindrome = product;
      }
    }
  }
  if (largestPalindrome == 0) {
    cout << "No palindromes ???" << endl;
  } else {
    cout << "Largest palindrome: " << largestPalindrome << endl;
  }
  return 0;
}

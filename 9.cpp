#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int target = 1000;

bool isTargetSum(int a, int b, int c) {
  return (a + b + c) == target;
}

bool isPythagoreanTriplet(int a, int b, int c) {
  return (a * a + b * b) == c * c;
}

int main(int argc, char** argv) {
  // This could be optimized by writing the loop in such a way where the sum is
  // always exactly 1000.
  for (int a = 1; a <= target; a++) {
    for (int b = a + 1; b <= target; b++) {
      for (int c = b + 1; c <= target; c++) {
        // Compute the Pythagorean triplet second, since it's more expensive.
        if (isTargetSum(a, b, c) && isPythagoreanTriplet(a, b, c)) {
          cout << "Found a, b, c: " << a << " " << b << " " << c << endl;
          cout << "Product: " << a * b * c << endl;
          return 0;
        }
      }
    }
  }
  return 0;
}

// a + b + c = 1000
// b = a + 1
// c = a + 2
// a + (a + 1) + (a + 2) = 1000
// 3 * a + 3 = 1000
// 3 * a = 997

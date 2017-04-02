#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int target = 500;

int divisorsCount(unsigned long n) {
  if (n == 1) {
    return 1;
  }
  // 1 and the number itself are divisors.
  int count = 2;
  unsigned long sqrtN = sqrt(n);
  for (unsigned long i = 2; i < sqrtN; i++) {
    if (n % i == 0) {
      // Any number below the sqrt will also have a divisor above the sqrt.
      count += 2;
      if (count > target) break;
    }
  }
  // cout << n << endl;
  return count;
}

unsigned long calculateTriangleNumber(unsigned long n) {
  return n * (n + 1) / 2;
}

int main(int argc, char** argv) {
  unsigned long triangleNumber = 0;
  while (divisorsCount(calculateTriangleNumber(++triangleNumber)) <= target) {}
  cout << "First triangle number with over " << target << " divisors: " << calculateTriangleNumber(triangleNumber) << endl;
  return 0;
}

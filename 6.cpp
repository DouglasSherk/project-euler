#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

unsigned long squareOfSum(unsigned long n) {
  unsigned long sum = n * (n + 1) / 2;
  return sum * sum;
}

unsigned long sumOfSquares(unsigned long n) {
  return n * (n + 1) * ((2 * n) + 1) / 6;
}

unsigned long target = 100;

int main(int argc, char** argv) {
  cout << "Diff. square of sum - sum of squares: "
       << squareOfSum(target) - sumOfSquares(target)
       << endl;
  return 0;
}

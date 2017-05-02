#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <math.h>

using namespace std;

int factorial(int n) {
  int sum = 1;
  for (int i = 1; i <= n; i++) {
    sum *= i;
  }
  return sum;
}

int digitFactorials(int n) {
  int sum = 0;
  while (n) {
    sum += factorial(n % 10);
    n /= 10;
  }
  return sum;
}

int main(int argc, char** argv) {
  int sum = 0;
  for (int i = 3; i < 9999999; i++) {
    if (digitFactorials(i) == i) {
      cout << "Digit factorial: " << i << endl;
      sum += i;
    }
  }
  cout << "Sum of all factorials: " << sum << endl;
}

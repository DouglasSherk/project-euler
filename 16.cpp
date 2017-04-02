#include <iostream>
#include <math.h>

#include <boost/multiprecision/cpp_int.hpp>

using namespace std;

int target = 1000;

int main(int argc, char** argv) {
  boost::multiprecision::cpp_int n = 1;
  for (int i = 0; i < target; i++) {
    n *= 2;
  }
  unsigned long long sum = 0;
  while (n) {
    sum += static_cast<unsigned long long>(n % 10);
    n /= 10;
  }
  cout << "Sum of all digits: " << sum << endl;
  return 0;
}

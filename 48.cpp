#include <iostream>
#include <math.h>

using namespace std;

typedef unsigned long long ull;

int gTarget = 1000;
int gNumDigits = 10;

ull power(int n, int k, ull modulo = 0) {
  ull temp = n;
  for (int i = 1; i < k; i++) {
    temp *= n;
    if (modulo != 0) {
      temp %= modulo;
    }
  }
  return temp;
}

int main(int argc, char** argv) {
  ull modulo = power(10, gNumDigits);

  ull result = 0;
  for (int i = 1; i <= gTarget; i++) {
    result += power(i, i, modulo);
    result %= modulo;
  }

  cout << "First " << gNumDigits << " digits of power series: " << result << endl;
  return 0;
}

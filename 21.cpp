#include <iostream>
#include <math.h>

using namespace std;

#define TARGET 10001

int sumsOfProperDivisors[TARGET] = {0};

int sumOfProperDivisor(int n) {
  if (sumsOfProperDivisors[n]) {
    return sumsOfProperDivisors[n];
  }

  bool seen[TARGET] = {false};
  int sum = 1;
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      cout << i << " and " << n / i << " are factors" << endl;
      sum += i;
      // Add in the other factor on the other side of the sqrt.
      sum += n / i;
    }
  }

  sumsOfProperDivisors[n] = sum;
  return sum;
}

int main(int argc, char** argv) {
  int sum = 0;
  bool seen[TARGET] = {false};
  for (int i = 1; i < TARGET; i++) {
    int a = i;
    int da = sumOfProperDivisor(a);
    cout << "Sum of proper divisors of " << a << ": " << da << endl;
    if (da >= TARGET) { continue; }
    int b = da;
    int db = sumOfProperDivisor(b);
    // cout << "Sum of proper divisors of " << b << ": " << db << endl;
    if (da < TARGET && db < TARGET && da == b && db == a && a != b && !seen[a] && !seen[b]) {
      seen[a] = true;
      seen[b] = true;
      cout << "Amicable pair: d(" << a << ") == d(" << b << ")" << endl;
      sum += da + db;
    }
  }
  cout << "Sum of all amicable numbers under " << TARGET << ": " << sum << endl;
  return 0;
}

#include <iostream>
#include <math.h>
#include <unordered_set>
#include <sstream>
#include <string>

using namespace std;

int pow(int n, int k) {
  int sum = 1;
  for (int i = 0; i < k; i++) {
    sum *= n;
  }
  return sum;
}

// Find the number of digits that this order of magnitude begins at.
void order(int n, int* result) {
  int o = 0;
  int i = 0;
  for (; i < log10(n); i++) {
    int slice = pow(10, i) * (i + 1) * 9;
    if (o + slice >= n) { break; }
    o += slice;
  }
  result[0] = i;
  result[1] = o;
}

int target = 7;

int main(int argc, char** argv) {
  int product = 1;
  for (int i = 0; i < target; i++) {
    int res[2];
    int upto = pow(10, i);
    order(upto, res);
    int step = res[0] + 1;
    int start = pow(10, step - 1);
    int digits = res[1];
    int num = start;
    while (digits < upto) {
      if (digits + step >= upto) {
        int digitPos = upto - digits - 1;
        string strify = to_string(num);
        int digit = strify[digitPos] - '0';
        product *= digit;
        cout << "digit (" << digit << ") is within " << digits << " and " << digits + step << ", num: " << num << ", pos: " << digitPos << " (" <<  step << ")" << endl;
        break;
      }
      num++;
      digits += step;
    }
  }
  cout << "Product of each digit is: " << product << endl;
  return 0;
}

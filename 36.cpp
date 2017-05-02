#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <math.h>
#include <sstream>

using namespace std;

int target = 1000000;

bool isPalindromic(string n) {
  return n == string(n.rbegin(), n.rend());
}

string to_string_base2(int n) {
  stringstream sstream;
  bool foundFirstBit = false;

  for (int i = 8 * sizeof(int) - 1; i >= 0; i--) {
    if (!foundFirstBit) {
      if (n & (1 << i)) {
        foundFirstBit = true;
      } else {
        // Continue on until we find the MSB.
        continue;
      }
    }

    if (n & (1 << i)) {
      sstream << "1";
    } else {
      sstream << "0";
    }
  }

  string retVal;
  sstream >> retVal;
  return retVal;
}

int main(int argc, char** argv) {
  int sum = 0;
  for (int i = 1; i < target; i++) {
    if (isPalindromic(to_string(i)) && isPalindromic(to_string_base2(i))) {
      cout << i << "(" << to_string_base2(i) << ") is palindromic in both bases" << endl;
      sum += i;
    }
  }
  cout << "Sum of all doubly-palindromic numbers: " << sum << endl;
  return 0;
}

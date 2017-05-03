#include <iostream>
#include <math.h>
#include <unordered_set>
#include <sstream>
#include <string>

using namespace std;

#define MAX_DIGITS 9

int target = 10000;

bool isPandigital(string& number) {
  bool digits[MAX_DIGITS + 1] = {false};

  for (auto it : number) {
    int digit = it - '0';
    if (digits[digit]) {
      return false;
    }
    digits[digit] = true;
  }

  for (int i = 1; i < MAX_DIGITS; i++) {
    if (!digits[i]) {
      return false;
    }
  }

  return true;
}

int main(int argc, char** argv) {
  string largestPandigital = "000000000";
  int largestI;
  int largestJ;

  for (int i = 1; i < target; i++) {
    for (int j = 2; j < MAX_DIGITS; j++) {
      stringstream strstream;
      string number;
      for (int k = 1; k <= j; k++) {
        strstream << i * k;
      }
      strstream >> number;
      if (number.length() == MAX_DIGITS) {
        if (isPandigital(number)) {
          cout << number << " is pandigital" << endl;
          if (number > largestPandigital) {
            largestPandigital = number;
            largestI = i;
            largestJ = j;
          }
        }
      } else if (number.length() > MAX_DIGITS) {
        break;
      }
    }
  }

  cout << "Largest pandigital is: " << largestPandigital << endl;
  cout << "Concatenated base: " << largestI << endl;
  cout << "n: " << largestJ << endl;

  return 0;
}

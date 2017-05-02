#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <math.h>
#include <sstream>
#include <string>
#include <unordered_set>

using namespace std;

int target = 100;

int gcd(int a, int b) {
  while (a != b) {
    if (a > b) {
      a -= b;
    } else {
      b -= a;
    }
  }
  return a;
}

bool duplicate(string& a, string& b) {
  for (auto it : a) {
    char dup = it;
    if (b.find(dup) != string::npos) {
      // cout << "Found dup : " << dup << " " << a << " " << b << endl;
      a.erase(a.find(dup), 1);
      b.erase(b.find(dup), 1);
      return true;
    }
  }
  return false;
}

bool duplicate(int a, int b) {
  string numerator = to_string(a), denominator = to_string(b);
  return duplicate(numerator, denominator);
}

double cancel(int a, int b) {
  string numerator = to_string(a), denominator = to_string(b);
  duplicate(numerator, denominator);

  if (numerator == "0" || denominator == "0") {
    return 0.0;
  }

  stringstream canceled1, canceled2;
  int numer, denom;

  canceled1 << numerator;
  canceled1 >> numer;

  canceled2 << denominator;
  canceled2 >> denom;

  // cout << "canceled: " << numer << " / " << denom << " = " << (double)numer / (double)denom << endl;
  return (double)numer / (double)denom;
}

double divide(double a, double b) {
  // cout << "divided: " << a << " / " << b << " = " << a / b << endl;
  return a / b;
}

int main(int argc, char** argv) {
  int numerator = 1;
  int denominator = 1;
  for (int a = 11; a < target; a++) {
    for (int b = a; b < target; b++) {
      if (a % 10 == 0 && b % 10 == 0) {
        continue;
      }
      if (a != b && duplicate(a, b) && abs(divide(a, b) - cancel(a, b)) < 0.000001) {
        cout << "One of those strange fractions: " << a << " / " << b << endl;
        numerator *= a;
        denominator *= b;
      }
    }
  }
  int gcdNumDenom = gcd(numerator, denominator);
  numerator /= gcdNumDenom;
  denominator /= gcdNumDenom;
  cout << "Product of lowest form of all divisors: " << numerator << " / " << denominator << endl;
  return 0;
}

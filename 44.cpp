#include <iostream>
#include <math.h>
#include <set>
#include <string>
#include <sstream>

using namespace std;

typedef unsigned long long ull;

int target = 10000;

ull generatePentagonalNumber(ull n) {
  return n * (3 * n - 1) / 2;
}

set<ull> generatePentagonalNumbers(ull n) {
  set<ull> pentagonalNumbers;
  for (ull i = 1; i <= n; i++) {
    pentagonalNumbers.insert(generatePentagonalNumber(i));
  }
  return pentagonalNumbers;
}

bool sumAndDifferenceArePentagonal(const set<ull>& pentagonalNumbers, ull i, ull j) {
  return pentagonalNumbers.find(j - i) != pentagonalNumbers.end() &&
         pentagonalNumbers.find(j + i) != pentagonalNumbers.end();
}

int main(int argc, char** argv) {
  set<ull> pentagonalNumbers(generatePentagonalNumbers(target));

  ull smallestDifference = -1;

  for (auto i = pentagonalNumbers.begin(); i != pentagonalNumbers.end(); i++) {
    for (auto j = i; j != pentagonalNumbers.end(); j++) {
      //cout << "Evaluating: " << *i << "," << *j << endl;
      if (!sumAndDifferenceArePentagonal(pentagonalNumbers, *i, *j)) { continue; }

      ull difference = *j - *i;
      if (smallestDifference == -1 || difference < smallestDifference) {
        cout << "New smallest difference at: " << difference << " (" << *i << ", " << *j << ") (i, j)" << endl;
        smallestDifference = difference;
      }
    }
  }
  cout << "Smallest difference of two pentagonals is: " << smallestDifference << endl;

  return 0;
}

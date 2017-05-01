#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <math.h>
#include <set>
#include <boost/multiprecision/gmp.hpp>
#include <boost/multiprecision/number.hpp>

using namespace std;
using namespace boost::multiprecision;

int target = 100;

int main(int argc, char** argv) {
  set<mpz_int> visited;

  for (int a = 2; a <= target; a++) {
    for (int b = 2; b <= target; b++) {
      mpz_int val = 1;
      for (int i = 0; i < b; i++) {
        val *= a;
      }
      visited.insert(val);
      cout << val << endl;
    }
  }

  cout << "Total unique elements: " << visited.size() << endl;

  return 0;
}

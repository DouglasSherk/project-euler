#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

unsigned long target = 1000000;

int main(int argc, char** argv) {
  unsigned long longestChainN = 0;
  unsigned long longestChainLength = 0;
  for (unsigned long i = 2; i < target; i++) {
    unsigned long chainLength = 0;
    unsigned long n = i;
    while (n != 1) {
      if (n % 2) {
        n = 3 * n + 1;
      } else {
        n /= 2;
      }
      if (++chainLength > longestChainLength) {
        longestChainN = i;
        longestChainLength = chainLength;
      }
    }
  }
  cout << "Longest chain is at: " << longestChainN << " (" << longestChainLength << " steps)" << endl;
  return 0;
}

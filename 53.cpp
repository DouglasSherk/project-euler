#include <iostream>
#include <set>
#include <vector>

#include "headers/euler.hpp"

const int MIN_N = 1;
const int MAX_N = 100;

const int MAX_VALUE = 1000000;

int main(int argc, char** argv) {
  int numAboveMax = 0;

  for (int n = MIN_N; n <= MAX_N; n++) {
    for (int r = 1; r <= n / 2; r++) {
      if (euler::choose(n, r) > MAX_VALUE) {
        std::cout << n << " choose " << r << " is above " << MAX_VALUE << std::endl;
        numAboveMax += n - r - r + 1;
        break;
      }
    }
  }

  std::cout << "23 choose 10: " << euler::choose(23, 10) << std::endl;

  std::cout << "Total terms in n {" << MIN_N << ".." << MAX_N << "} above " << MAX_VALUE << ", "
            << "r <= n, "
            << "for n choose r: "
            << numAboveMax
            << std::endl;
  return 0;
}

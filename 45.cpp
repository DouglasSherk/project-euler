#include <iostream>
#include <math.h>
#include <set>
#include <string>
#include <sstream>

using namespace std;

int start = 286;

typedef unsigned long long ull;

ull generateTriangleNumber(ull n) {
  return n * (n + 1) / 2;
}

ull generatePentagonalNumber(ull n) {
  return n * (3 * n - 1) / 2;
}

ull generateHexagonalNumber(ull n) {
  return n * (2 * n - 1);
}

int main(int argc, char** argv) {
  ull T = -1, P = -2, H = -3;

  // Naive solution: Iterate until you've found it. Too slow: O(T_n * P_n * H_n)
  /*
  for (ull T_n = start; T != P || T != H; T_n++) {
    T = generateTriangleNumber(T_n);
    for (ull P_n = 1; P < T; P_n++) {
      P = generatePentagonalNumber(P_n);
      for (ull H_n = 1; H < T; H_n++) {
        H = generateHexagonalNumber(H_n);
      }
    }
  }
  */

  // Better solution: bisect along P_n and H_n: O(T_n * log(P_n) * log(H_n))
  for (int T_n = start; T != P || T != H; T_n++) {
    T = generateTriangleNumber(T_n);

    int P_n_low = 0, P_n_high = 1000000;

     while (abs(P_n_low - P_n_high) > 1) {
      int P_n = (P_n_low + P_n_high) / 2;

      P = generatePentagonalNumber(P_n);

      if (P > T) {
        P_n_high = P_n;
      } else if (P < T) {
        P_n_low = P_n;
      }

      if (P == T) { break; }
    }

    if (P != T) {
      continue;
    }

    int H_n_low = 0, H_n_high = 1000000;

    while (abs(H_n_low - H_n_high) > 1) {
      int H_n = (H_n_low + H_n_high) / 2;

      H = generateHexagonalNumber(H_n);

      if (H > T) {
        H_n_high = H_n;
      } else if (H < T) {
        H_n_low = H_n;
      }

      if (H == T) { break; }
    }
  }

  if (H == T) {
    cout << "Found triangle number that is also pentagonal and hexagonal: " << T << endl;
  } else {
    cout << "No matching triangle number found" << endl;
  }

  return 0;
}

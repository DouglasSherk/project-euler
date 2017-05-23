#ifndef __EULER_PERMUTATIONS_INCLUDED_
#define __EULER_PERMUTATIONS_INCLUDED_

#include <string>
#include <utility>
#include <algorithm>
#include <climits>

#include "types.hpp"

namespace euler {

bool nextPermutation(std::string& n) {
  // 1. Find largest x s.t. P[x]<P[x+1]
  int x = -1;
  for (int i = n.length() - 2; i >= 0; i--) {
    if (n[i] < n[i + 1]) {
      x = i;
      break;
    }
  }

  // 1a. If there is no such x, then this was the last permutation.
  if (x == -1) {
    return false;
  }

  // 2. Find largest y s.t. P[x]<P[y]
  int y = -1;
  for (int i = n.length() - 1; i >= 0; i--) {
    if (n[x] < n[i]) {
      y = i;
      break;
    }
  }

  // 3. Swap P[x] and P[y]
  std::swap(n[x], n[y]);

  // 4. Reverse P[x+1]..P[n]
  std::reverse(n.begin() + x + 1, n.end());

  return true;
}

bool nextPermutation(int& n) {
  std::string permutation = std::to_string(n);
  bool retVal = nextPermutation(permutation);
  n = toInt(permutation);
  return retVal;
}

bool isPermutation(const std::string& a, const std::string& b) {
  unsigned char charsA[UCHAR_MAX] = {0}, charsB[UCHAR_MAX] = {0};

  for (auto c : a) {
    charsA[(unsigned char)c]++;
  }
  for (auto c : b) {
    charsB[(unsigned char)c]++;
  }

  for (int i = 0; i < UCHAR_MAX; i++) {
    if (charsA[i] != charsB[i]) {
      return false;
    }
  }

  return true;
}

bool isPermutation(int a, int b) {
  return isPermutation(std::to_string(a), std::to_string(b));
}

}

#endif // __EULER_PERMUTATIONS_INCLUDED_

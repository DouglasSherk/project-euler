#ifndef __EULER_COMBINATORICS_INCLUDED_
#define __EULER_COMBINATORICS_INCLUDED_

#include <string>
#include <utility>
#include <algorithm>
#include <climits>

namespace euler {

long long factorial(int n, int start = 0) {
  long long sum = 1;

  for (int i = start + 1; i <= n; i++) {
    sum *= i;
  }

  return sum;
}

#include <iostream>

long long choose(int n, int r) {
  if (r < n / 2) {
    return factorial(n, n - r) / factorial(r);
  } else {
    return factorial(n, r) / factorial(n - r);
  }
}

}

#endif // __EULER_COMBINATORICS_INCLUDED_

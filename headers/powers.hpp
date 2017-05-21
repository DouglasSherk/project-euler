#ifndef __EULER_POWERS_INCLUDED_
#define __EULER_POWERS_INCLUDED_

namespace euler {

template <class T>
T power(T n, int k) {
  T sum = 1;

  for (int i = 0; i < k; i++) {
    sum *= n;
  }

  return sum;
}

}

#endif // __EULER_POWERS_INCLUDED_

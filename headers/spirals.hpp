#ifndef __EULER_SPIRALS_INCLUDED_
#define __EULER_SPIRALS_INCLUDED_

#include <vector>

namespace euler {

template <class T>
std::vector<std::vector<T>> generateSpiral(int size) {
  std::vector<std::vector<T>> spiral(size, std::vector<T>(size, 0));
  int center = size / 2;
  spiral[center][center] = 1;

  int x;
  int y;

  for (int layer = 1, i = 1; i < size * size; layer++) {
    // - - - - -
    // -       X
    // -       X
    // -       X
    // - - - - X
    for (x = center + layer, y = center - layer + 1; y <= center + layer; y++) {
      spiral[x][y] = ++i;
    }

    // - - - - -
    // -       -
    // -       -
    // -       -
    // X X X X -
    for (x = center + layer - 1, y = center + layer; x >= center - layer; x--) {
      spiral[x][y] = ++i;
    }

    // X - - - -
    // X       -
    // X       -
    // X       -
    // - - - - -
    for (x = center - layer, y = center + layer - 1; y >= center - layer; y--) {
      spiral[x][y] = ++i;
    }

    // - X X X X
    // -       -
    // -       -
    // -       -
    // - - - - -
    for (x = center - layer + 1, y = center - layer; x <= center + layer; x++) {
      spiral[x][y] = ++i;
    }
  }

  return spiral;
}

}

#endif // __EULER_SPIRALS_INCLUDED_

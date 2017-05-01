#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <math.h>

using namespace std;

#define SIZE 1001

// #define DEBUG

#ifdef DEBUG
  #undef SIZE
  #define SIZE 5
#endif

int main(int argc, char** argv) {
  int spiral[SIZE][SIZE];
  int center = SIZE / 2;
  spiral[center][center] = 1;

  int x;
  int y;

  for (int layer = 1, i = 1; i < SIZE * SIZE; layer++) {
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

#ifdef DEBUG
  int width = log(SIZE) + 2;
  for (y = 0; y < SIZE; y++) {
    for (x = 0; x < SIZE; x++) {
      cout << setw(width) << spiral[x][y];
    }
    cout << endl;
  }
#endif

  unsigned long long sum = spiral[center][center];
  for (int i = 1; i <= SIZE / 2; i++) {
    // X - -
    // - - -
    // - - -
    sum += spiral[center - i][center - i];

    // - - X
    // - - -
    // - - -
    sum += spiral[center + i][center - i];

    // - - -
    // - - -
    // - - X
    sum += spiral[center + i][center + i];

    // - - -
    // - - -
    // X - -
    sum += spiral[center - i][center + i];
  }

#ifdef DEBUG
  if (sum != 101) {
    throw logic_error("Diagonals should evaluate to 101");
  }
#endif

  cout << "Diagonal sum is: " << sum << endl;

  return 0;
}

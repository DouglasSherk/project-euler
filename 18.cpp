/*
Dynamic programming approach. The best cost of each node in the pyramid can be
represented by a series of sub-problems of the highest value path beneath it.
 */

#include <iostream>
#include <math.h>
#include "Vector.h"
#include <string>

using namespace std;

#define PYRAMID_ROWS 15

int main(int argc, char** argv) {
  int pyramid[PYRAMID_ROWS][PYRAMID_ROWS] = {
    {75},
    {95, 64},
    {17, 47, 82},
    {18, 35, 87, 10},
    {20,  4, 82, 47, 65},
    {19,  1, 23, 75,  3, 34},
    {88,  2, 77, 73,  7, 63, 67},
    {99, 65,  4, 28,  6, 16, 70, 92},
    {41, 41, 26, 56, 83, 40, 80, 70, 33},
    {41, 48, 72, 33, 47, 32, 37, 16, 94, 29},
    {53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14},
    {70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57},
    {91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48},
    {63, 66,  4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31},
    { 4, 62, 98, 27, 23,  9, 70, 98, 73, 93, 38, 53, 60,  4, 23}
  };

  unsigned long long sums[PYRAMID_ROWS][PYRAMID_ROWS] = {0};

  for (int i = PYRAMID_ROWS - 1; i >= 0; i--) {
    for (int j = 0; j <= i; j++) {
      int add = 0;
      if (i < PYRAMID_ROWS - 1) {
        add = sums[i + 1][j] > sums[i + 1][j + 1] ?
          sums[i + 1][j] :
          sums[i + 1][j + 1];
      }
      sums[i][j] = pyramid[i][j] + add;
      cout << "{" << i << "," << j << "} sum: " << sums[i][j] << " for: " << pyramid[i][j] << endl;
    }
  }

  cout << "The highest value path is: " << sums[0][0] << endl;

  return 0;
}

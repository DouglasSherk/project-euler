#include <iostream>
#include <math.h>

using namespace std;

#define SIZE 20

int main(int argc, char** argv) {
  unsigned long long grid[SIZE + 1][SIZE + 1];
  for (int i = 0; i < SIZE; i++) {
    grid[i][SIZE] = 1;
    grid[SIZE][i] = 1;
  }
  for (int i = SIZE - 1; i >= 0; i--) {
    for (int j = SIZE - 1; j >= 0; j--) {
      grid[i][j] = grid[i + 1][j] + grid[i][j + 1];
    }
  }
  cout << "Total paths: " << grid[0][0] << endl;
  return 0;
}

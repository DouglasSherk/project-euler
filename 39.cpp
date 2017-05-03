#include <iostream>
#include <math.h>
#include <unordered_set>
#include <sstream>
#include <string>

using namespace std;

int target = 1000;

int squareRoot(int n) {
  int s = sqrt(n);
  if (s * s != n) { return -1; }
  return s;
}

int main(int argc, char** argv) {
  int largestSolutionsP = -1;
  int largestSolutionsNum = 0;
  for (int p = 1; p <= target; p++) {
    int solutionsNum = 0;
    for (int a = 1; a <= p; a++) {
      for (int b = 1; b <= p; b++) {
        if (a + b > p) {
          break;
        }
        int product = a * a + b * b;
        int c = squareRoot(product);
        if (c == -1) {
          continue;
        }
        if (a + b + c == p) {
          solutionsNum++;
          cout << "Found a solution for " << p << endl;
          if (p == largestSolutionsP) {
            largestSolutionsNum = solutionsNum;
          } else if (solutionsNum > largestSolutionsNum){
            largestSolutionsP = p;
            largestSolutionsNum = solutionsNum;
          }
        }
      }
    }
  }
  cout << "Perimeter with largest number of solutions: " << largestSolutionsP << " with " << largestSolutionsNum << " solutions" << endl;
  return 0;
}

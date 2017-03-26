#include <iostream>

using namespace std;

unsigned int sum = 0;

int main(int argc, char** argv) {
  // In Project Euler, they begin at 1 and 2 instead of 0 and 1 for some reason.
  unsigned int t1 = 1;
  unsigned int t2 = 2;
  if (t1 % 2 == 0) {
    sum += t1;
  }
  cout << t1 << endl;
  while (t2 < 4000000) {
    if (t2 % 2 == 0) {
      sum += t2;
      cout << '+';
    }
    cout << t2 << endl;
    unsigned int temp = t2;
    t2 += t1;
    t1 = temp;
  }
  cout << sum << endl;
  return 0;
}

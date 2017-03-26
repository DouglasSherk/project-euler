#include <iostream>

using namespace std;

int main(int argc, char** argv) {
  unsigned int sum = 0;
  for (unsigned int i = 0; i < 1000; i++) {
    if (i % 3 == 0 || i % 5 == 0) {
      sum += i;
    }
  }
  cout << sum << endl;
  return 0;
}

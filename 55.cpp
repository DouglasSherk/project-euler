#include <iostream>

#include "headers/euler.hpp"

const int MIN_NUM = 1;
const int MAX_NUM = 10000;
const int MAX_ADDITIONS = 50;

int main(int argc, char** argv) {
  int numLychrelNumbers = 0;

  for (int i = MIN_NUM; i < MAX_NUM; i++) {
    long long sum = i;

    // Some numbers such as 4994 are both palindromic and Lychrel numbers.
    for (int j = 1; j <= MAX_ADDITIONS && (!euler::isPalindromic(sum) || sum == i); j++) {
      sum += euler::reverseInt(sum);
    }

    if (!euler::isPalindromic(sum)) {
      std::cout << i << " is a Lychrel number" << std::endl;
      numLychrelNumbers++;
    } else {
      std::cout << i << " is not a Lychrel number (adds up to " << sum << ")" << std::endl;
    }
  }

  std::cout << "Total Lychrel numbers below " << MAX_NUM << ": " << numLychrelNumbers << std::endl;

  return 0;
}

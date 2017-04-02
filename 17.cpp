#include <iostream>
#include <math.h>
#include "Vector.h"
#include <string>

using namespace std;

#define _SPECIAL_CASES 10
#define _SPECIAL_CASES_BEGIN 10

#define _POWERS_OF_ZERO 10
#define _POWERS_OF_TEN 10

string specialCaseWord(int n) {
  n %= 100;

  if (n < _SPECIAL_CASES_BEGIN || n >= _SPECIAL_CASES_BEGIN + _SPECIAL_CASES) {
    return "";
  }

  string specialCases[_SPECIAL_CASES] = {
    "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen",
    "seventeen", "eighteen", "nineteen"
  };
  return specialCases[n - _SPECIAL_CASES_BEGIN];
}

string numberInWords(int n) {
  string powersOfZero[_POWERS_OF_ZERO] = {
    // We never write out "zero", so cut out the middle man and don't store it.
    "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
  };

  string powersOfOne[_POWERS_OF_TEN] = {
    "", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy",
    "eighty", "ninety"
  };

  if (n >= 1 && n < _SPECIAL_CASES_BEGIN) {
    return powersOfZero[n];
  }

  if (n >= _SPECIAL_CASES_BEGIN && n < _SPECIAL_CASES_BEGIN + _SPECIAL_CASES) {
    return specialCaseWord(n);
  }

  if (n > _SPECIAL_CASES && n < 100) {
    return powersOfOne[n / 10] + " " + powersOfZero[n % 10];
  }

  if (n >= 100 && n < 1000) {
    string words = powersOfZero[n / 100] + " hundred";
    string special = specialCaseWord(n);
    if (special.length()) {
      words += " and " + special;
    } else if (n % 100) {
      words += " and";
      int powerOfOne = (n % 100) / 10;
      if (powerOfOne) {
        words += " " + powersOfOne[powerOfOne];
      }
      int powerOfZero = n % 10;
      if (powerOfZero) {
        words += " " + powersOfZero[powerOfZero];
      }
    }
    return words;
  }

  if (n == 1000) {
    return "one thousand";
  }

  return "";
}

int target = 1000;

int main(int argc, char** argv) {
  Vector<string> numbersInWords;

  // Insert something in the zero position.
  numbersInWords.insertBack("");

  for (int i = 1; i <= target; i++) {
    numbersInWords.insertBack(numberInWords(i));
  }

  int sumOfCharacters = 0;
  for (int i = 1; i <= target; i++) {
    cout << numbersInWords[i] << endl;
    for (int j = 0; j < numbersInWords[i].length(); j++) {
      if (numbersInWords[i][j] >= 'a' && numbersInWords[i][j] <= 'z') {
        sumOfCharacters++;
      }
    }
  }

  cout << "Total characters in equivalent words for numbers from 1 to " << target << ": " << sumOfCharacters << endl;

  return 0;
}

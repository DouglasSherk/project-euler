#include <iostream>
#include <math.h>
#include <unordered_set>
#include <string>
#include <fstream>

using namespace std;

int target = 9999;

unordered_set<string> readWordsFromFile(string file) {
  ifstream wordsFile(file);

  unordered_set<string> words;

  string word;
  while (getline(wordsFile, word, ',')) {
    word.erase(remove(word.begin(), word.end(), '\"'), word.end());
    words.insert(word);
  }

  return words;
}

int triangleNumber(int n) {
  return n * (n + 1) / 2;
}

unordered_set<int> generateTriangleNumbers(int n) {
  unordered_set<int> triangleNumbers;

  for (int i = 0; i < n; i++) {
    triangleNumbers.insert(triangleNumber(i));
  }

  return triangleNumbers;
}

short charToInt(char c) {
  return c - 'A' + 1;
}

int stringToInt(string word) {
  int sum = 0;
  for (auto it : word) {
    sum += charToInt(it);
  }
  return sum;
}

bool isTriangleNumber(int n, unordered_set<int>& triangleNumbers) {
  return triangleNumbers.find(n) != triangleNumbers.end();
}

int main(int argc, char** argv) {
  unordered_set<int> triangleNumbers(generateTriangleNumbers(target));
  unordered_set<string> words(readWordsFromFile("42_words.txt"));

  int totalTriangleNumbers = 0;

  for (auto word : words) {
    int convertedWord = stringToInt(word);
    if (isTriangleNumber(convertedWord, triangleNumbers)) {
      cout << word << " in converted form is a triangle number: " << convertedWord << endl;
      totalTriangleNumbers++;
    }
  }

  cout << "Total number of converted form words that are triangle numbers: " << totalTriangleNumbers << endl;

  return 0;
}
